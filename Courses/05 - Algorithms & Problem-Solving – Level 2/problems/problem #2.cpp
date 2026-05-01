

#include <iostream>
#include <cmath>
using namespace std;

enum enCheckPrime {Prime =1, NotPrime =2};

int ReadPositiveNumber(string message) {

    int number;
    do {
        cout << message;
        cin >> number;
    }
    while (number <= 0);
    return number;
}

enCheckPrime CheckPrime(int number) {

    short M = round(number / 2);

    for (int i = 2;i <= M;i++) {
        if (number % i == 0)
            return NotPrime;
    }
    return Prime;
   
}

void PrintPrimeNumbers(int number) {
    cout << "\n\nPRINT PRIME NUMBERS FROM 1 TO N:\n";

    for (int i = 1; i < number; i++)
    {
        if (CheckPrime(i) == enCheckPrime::Prime)

            cout << i << endl;
    }

}



int main()
{
    PrintPrimeNumbers(ReadPositiveNumber("please enter a positive number: "));
}