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

int SumOfDigits(int number) {
    int sum = 0;
    int Remainder = 0;

    while (number) {
        Remainder = number % 10;
        number /= 10;
        sum += Remainder;

    }
    return sum;
}
int main()
{
    cout << "\n\nSum Of Digits = " << SumOfDigits(ReadPositiveNumber("please enter a positive number: "));
}