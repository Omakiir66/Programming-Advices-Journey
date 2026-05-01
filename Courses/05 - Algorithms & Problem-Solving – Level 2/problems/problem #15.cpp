
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

void PrintLetterPattern(int number) {

    for (short i = 65; i <= 65 + (number - 1); i++) {

        for (short j = 1; j <= i -65 + 1; j++) {

            cout << char(i);
        }
        cout << endl;
    }
}


int main()
{

    PrintLetterPattern(ReadPositiveNumber("please, enter a positive number: "));

}