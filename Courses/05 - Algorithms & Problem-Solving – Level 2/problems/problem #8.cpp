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
int main()
{
    int number = ReadPositiveNumber("please enter a positive number: ");
    short digit = ReadPositiveNumber("please enter a positive digit: ");

    cout << "\nDigit " << digit << " Frequency is " << DigitFrequency(number, digit) << " Times(s).\n";
}