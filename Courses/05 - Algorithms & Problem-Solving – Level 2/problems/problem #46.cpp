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
float Myabs(float number) {
    if (number > 0)
        return number;
    else
        return number * -1;
    
}


int main()
{
    float number = ReadNumber();
    cout << "My abs Result : " << Myabs(number) << endl;
    cout << "C++ abs Result: " << abs(number);

}