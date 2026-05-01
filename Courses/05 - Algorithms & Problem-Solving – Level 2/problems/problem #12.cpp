
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

void PrintInvertedPattern(int number) {

    for (short i = number; i >= 1; i--) {

        for (short j = 1; j <= i; j++) {

            cout << i;
        }
        cout <<endl;
    }
}


int main()
{
    
    PrintInvertedPattern(ReadPositiveNumber("please, enter a positive number: "));

}