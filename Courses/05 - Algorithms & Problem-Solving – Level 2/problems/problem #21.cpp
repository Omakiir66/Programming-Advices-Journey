#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum TextType { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4 };

 int ReadPositiveNumber(string message) {
        int number;
        do {
            cout << message;
            cin >> number;
        } while (number <= 0);
        return number;
}


int RandomNumber(int From, int To) {
    return  rand() % (To - From + 1) + From;
}


char GetRandomChar(TextType type) {

    switch (type) {

    case SmallLetter:
        return char(RandomNumber(97, 122));
        break;
    case CapitalLetter:
        return char(RandomNumber(65, 90));
        break;
    case SpecialChar:
        return char(RandomNumber(33, 47));
        break;

    case Digit:
        return char(RandomNumber(48, 57));
        break;

    default:
        return char(RandomNumber(97, 122));

    }


}


string GenerateWord(TextType type, short Length) {
    string word = "";
    for (int i = 0; i < Length; i++) 
    {
        word += GetRandomChar (type);
    }

    return word;
}

string GenerateKey() {
    string key = "";
    
    key = GenerateWord(CapitalLetter, 4) + "-";
    key = key + GenerateWord(CapitalLetter, 4) + "-";
    key = key + GenerateWord(CapitalLetter, 4) + "-";
    key = key + GenerateWord(CapitalLetter, 4) ;

    return key;
}


void GenerateKeys(int numberOfKeys) {

    for (int i = 1;i <= numberOfKeys; i++) {
        cout << "Key[" << i << "]:" 
            << GenerateKey() << endl;
    }

}

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumber("please enter how many keys to generate: "));
    

}