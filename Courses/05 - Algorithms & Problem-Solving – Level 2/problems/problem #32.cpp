#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int RandomNumber(int From, int To) {
    return  rand() % (To - From + 1) + From;
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


void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength) {
    
    for (int i = 0;i < arrLength ;i++) {
        arrDestination[i] = arrSource[arrLength - 1 - i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arrLength;

    FillArrayWithRandomElements(arr1, arrLength);
    CopyArrayInReverseOrder(arr1, arr2, arrLength);

    cout << "Array 1 Elements: \n";
    PrintArray(arr1, arrLength);

    cout << "\n\nArray 2 Elements after copying array 1 in reversed order: \n";
    PrintArray(arr2, arrLength);
}