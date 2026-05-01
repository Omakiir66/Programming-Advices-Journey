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
        word += GetRandomChar(type);
    }

    return word;
}

string GenerateKey() {
    string key = "";

    key = GenerateWord(CapitalLetter, 4) + "-";
    key = key + GenerateWord(CapitalLetter, 4) + "-";
    key = key + GenerateWord(CapitalLetter, 4) + "-";
    key = key + GenerateWord(CapitalLetter, 4);

    return key;
}

void FillArrayWithKeys(string arr[100], int &arrLength) {

    for (int i = 0;i < arrLength; i++) {
        arr[i] = GenerateKey();
    }
}

void printKeysInArray(string arr[100], int arrLength) {
    cout << "\nArray Elements:\n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array[" << i << "]:" << arr[i] << endl;

    }
}

int main()
{
    srand((unsigned)time(NULL));

    string arr[100]; int arrLength;
   
    arrLength = ReadPositiveNumber("please enter how many keys to generate: ");

    FillArrayWithKeys(arr, arrLength);
    printKeysInArray(arr, arrLength);

}