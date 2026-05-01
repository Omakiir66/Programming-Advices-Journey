#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
enum TextType {SmallLetter = 1 , CapitalLetter = 2, SpecialChar =3, Digit =4};


int RandomNumber(int From, int To) {
    return  rand() % (To - From + 1) + From;
}

char GetRandomChar(TextType type) {

    switch (type) {
       
    case SmallLetter:
        return char(RandomNumber(97, 122)) ;
        break;
    case CapitalLetter:
        return char(RandomNumber(65, 90)) ;
        break;
    case SpecialChar:
        return char(RandomNumber(33, 47)) ;
        break;

    case Digit:
         return char(RandomNumber(48, 57));
        break;

    default:
        return char(RandomNumber(97, 122)) ;

    }


}

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomChar(SmallLetter) <<endl;
    cout << GetRandomChar(CapitalLetter) << endl;
    cout << GetRandomChar(SpecialChar) << endl;
    cout << GetRandomChar(Digit) << endl;

}