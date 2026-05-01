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
float GetFractionPart(float number) {
    return number - int(number);
}

int MyCeil(float number) {

    int intPart = int(number);
    float FractionPart = GetFractionPart(number);

    /*if (FractionPart == 0.0 || FractionPart <0.0)
        return int(number);

    else
        return int(number) + 1;*/

    if (abs(FractionPart) > 0) {
        if (number > 0)
            return int(number) + 1;
        else
            return int(number);
    }
    else
        return int(number);

   
}

int main()
{
    float number = ReadNumber();
    cout << "My Ceil Result : " << MyCeil(number) << endl;
    cout << "C++ Ceil Result: " << ceil(number);

}