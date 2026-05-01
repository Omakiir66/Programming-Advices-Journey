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

int MinElementInArray(int arr[100], int arrLength) {
    int minNumber = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] < minNumber)
            minNumber = arr[i];
    }
    return minNumber;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length;

    FillArrayWithRandomElements(arr, Length);

    cout << "Array Elements: ";
    PrintArray(arr, Length);

    cout << "\nMin Number is: " << MinElementInArray(arr, Length);

}