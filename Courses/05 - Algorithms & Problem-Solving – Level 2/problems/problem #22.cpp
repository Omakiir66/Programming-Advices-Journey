#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string message) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

void ReadArray(int arr[100], int& arrLength) {
    cout << "please enter the number of Elements: \n\n";
    cin >> arrLength;

    cout << "Enter array Elements: \n";
    for (int i = 0;i < arrLength; i++) {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int CheckNumber(int arr[100], int Length, int NumberToCheck) {
    int count = 0;

    for (int i = 0; i < Length; i++) {

        if (NumberToCheck == arr[i])
            count++;
    }
    return count;
}

int main()
{
    int arr[100], Length;
    int NumberToCheck;

   ReadArray(arr, Length);

   NumberToCheck = ReadPositiveNumber("please enter a number To check: ");

   cout << "Original Array: ";
   PrintArray(arr, Length);

   cout << NumberToCheck << " is repeated " << CheckNumber(arr,Length, NumberToCheck) << " Time(s).";


}