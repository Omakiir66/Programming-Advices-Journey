
#include <iostream>
#include <cmath>

using namespace std;


int ReadPositiveNumber(string message) {

    int number;
    do {
    cout << message;
    cin >> number;
    } 
    while (number <= 0);
    return number;

}


 bool IsPerfect(int number) {
     int sum = 0;

     for (int i = 1; i < number;i++)
     {
         if (number % i == 0)
             sum += i;
     }
     return number == sum;
   
 }

 void PrintResults(int number) {
     if (IsPerfect(number))
         cout << number << " is perfect.\n";
     else
         cout << number << " is not perfect.\n";
 }

int main()
{
    PrintResults(ReadPositiveNumber("please enter a positive number:"));
}



