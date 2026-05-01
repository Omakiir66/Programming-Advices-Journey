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

int RandomNumber(int From, int To) {
    return  rand() % (To - From + 1) + From;
}

void FillArrayWithRandomElements(int arr[100], int arrLength) {

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

void  Sum2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100];
    int arrLength = ReadPositiveNumber("please enter how many elements: ");

    FillArrayWithRandomElements(arr1, arrLength);
    FillArrayWithRandomElements(arr2, arrLength);

    int arrSum[100];
    Sum2Arrays(arr1, arr2, arrSum, arrLength);

    cout << "Array 1 Elements: \n";
    PrintArray(arr1, arrLength);

    cout << "\n\nArray 2 Elements: \n";
    PrintArray(arr2, arrLength);

    cout << "\n\nSum of Array 1 and Array 2 Elements: \n";
    PrintArray(arrSum, arrLength);

}