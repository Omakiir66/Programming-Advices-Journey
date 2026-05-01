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
//-10.3
int MyRound(float number) {

    int intPart = int(number); //-10
    float FractionPart = GetFractionPart(number); //-0.7
   
    if (abs(FractionPart) >= 0.5) {

        if (number > 0)
            return ++intPart; //11
        else
            return --intPart;//-11
        
    }
    else {
        
        return intPart;
    }
    

}

int main()
{
    float number = ReadNumber();
    cout << "My Round Result : " << MyRound(number) << endl;
    cout << "C++ Round Result: " << round(number);

}