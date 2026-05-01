
#include <iostream>
#include <cmath>
using namespace std;



int ReadPositiveNumber(string message) {

    int number;
    do {

        cout << message;
        cin >> number;
    } while (number <= 0);

    return number;
}

void PrintInvertedLetterPattern(int number) {

    for (short i = 65 + (number -1) ; i >= 65; i--) {

        for (short j = 65; j <= i; j++) {

            cout << char(i);
        }
        cout << endl;
    }
}


int main()
{

    PrintInvertedLetterPattern(ReadPositiveNumber("please, enter a positive number: "));

}