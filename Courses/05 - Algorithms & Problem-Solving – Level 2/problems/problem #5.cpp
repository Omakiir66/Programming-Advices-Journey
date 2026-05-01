
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

 void PrintDigitsInReversedOrder(int number) {
     int Remainder = 0;

     while (number) {
         Remainder = number % 10;
         number /= 10;
         cout << Remainder << endl;
         
     }
 }
int main()
{
    PrintDigitsInReversedOrder(ReadPositiveNumber("please, enter a positive number: "));
}