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


bool IsPerfect(int number) {
    int sum = 0;

    for (int i = 1; i < number;i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return number == sum;

}

void PrintPerfectNumbersFrom1ToN(int number) {
    cout << endl;
    for (int i = 1; i <= number; i++) {

        if (IsPerfect(i))
            cout << i << endl;
    }
}

int main()
{
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("please, enter a positive number here: "));
}