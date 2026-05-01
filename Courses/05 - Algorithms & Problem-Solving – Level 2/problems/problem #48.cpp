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

int MyFloor(float number) {

    if (number > 0)
        return int(number);
    else
        return int(number) - 1;


}

int main()
{
    float number = ReadNumber();
    cout << "My Floor Result : " << MyFloor(number) << endl;
    cout << "C++ Floor Result: " << floor(number);

}