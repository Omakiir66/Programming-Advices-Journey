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

int ReverseNumber(int number) {
    int Number2 = 0, Remainder = 0;

    while (number) {
        Remainder = number % 10;
        number /= 10;
        Number2 = Number2 *10 + Remainder;

    }
    return Number2;
}
int main()
{
    int number = ReadPositiveNumber("please enter a positive number: ");
   cout<<"\nReverse is : \n"
       << ReverseNumber(number);
}