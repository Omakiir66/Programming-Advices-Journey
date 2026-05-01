#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enCheckPrime { Prime = 1, NotPrime = 2 };

int RandomNumber(int From, int To) {
    return  rand() % (To - From + 1) + From;
}

void AddArrayElement(int arr[100], int& arrLength, int  Number) {
    arr[arrLength] = Number;
    arrLength++;
}

void FillArrayWithRandomElements(int arr[100], int& arrLength) {

    cout << "please enter the number of Elements: \n\n";
    cin >> arrLength;

    for (int i = 0;i < arrLength; i++) {

        arr[i] = RandomNumber(1, 100);
    }
    cout << endl;
}

void PrintArray(int arr[100], int Length) {

    for (int i = 0; i < Length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

enCheckPrime CheckPrime(int number) {
    short M = round(number / 2);
    for (int i = 2;i <= M;i++) {
        if (number % i == 0)
            return NotPrime;
    }
    return Prime;

}
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {

    for (int i = 0;i < arrLength;i++)
    {
        if (CheckPrime(arrSource[i]) == Prime )
            AddArrayElement(arrDestination, arr2Length, arrSource[i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arrLength, arr2Length = 0;

    FillArrayWithRandomElements(arr1, arrLength);
     
    CopyPrimeNumbers(arr1, arr2, arrLength, arr2Length);

    cout << "Array 1 Elements: \n";
    PrintArray(arr1, arrLength);

    cout << "\n\nArray 2 Prime Elements: \n";
    PrintArray(arr2, arr2Length);
}