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


int DigitFrequency(int number, short digit) {
    int Remainder = 0, count = 0;
    while (number) {

        Remainder = number % 10;
        number /= 10;

        if (digit == Remainder)
            count++;

    }
    return count;
}


void PrintAllDigitsFrequency(int number) {

    for (int i = 0;i <= 9; i++) 
    {
        if (DigitFrequency(number, i) > 0)

            cout << "\nDigit " << i << " Frequency is " << DigitFrequency(number, i) << " Times(s).";
    }
}
int main()
{
    int number = ReadPositiveNumber("please enter a positive number: ");
    PrintAllDigitsFrequency(number);
   
}