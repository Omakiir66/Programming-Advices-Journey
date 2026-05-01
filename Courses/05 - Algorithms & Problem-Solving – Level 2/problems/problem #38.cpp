#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


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

void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {

    for (int i = 0;i < arrLength;i++) 
    {

        if(arrSource[i] %2 !=0)
            AddArrayElement(arrDestination, arr2Length, arrSource[i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arrLength, arr2Length = 0;

    FillArrayWithRandomElements(arr1, arrLength);

    CopyOddNumbers(arr1, arr2, arrLength, arr2Length);

    cout << "Array 1 Elements: \n";
    PrintArray(arr1, arrLength);

    cout << "\n\nArray 2 Odd Elements: \n";
    PrintArray(arr2, arr2Length);
}