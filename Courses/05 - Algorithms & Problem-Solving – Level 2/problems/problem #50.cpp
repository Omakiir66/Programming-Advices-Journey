#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber() {

    float number;
    cout << "please enter a number: ";
    cin >> number;
    cout << endl;
    return number;

}

float MySqrt(float number) {
    return pow(number, 0.5);

}

int main()
{
    float number = ReadNumber();
    cout << "My Sqrt Result : " << MySqrt(number) << endl;
    cout << "C++ Sqrt Result: " << sqrt(number);

}