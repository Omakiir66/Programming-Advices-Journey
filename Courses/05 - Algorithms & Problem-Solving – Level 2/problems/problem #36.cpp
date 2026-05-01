#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadNumber() {
    int number;
    cout << "please enter a number: ";
    cin >> number;
    return number;
}

void AddArrayElement(int arr[100], int &arrLength,int  Number) {
    arr[arrLength] = Number;
    arrLength++;
}

void InputUserNUmbersInArray(int arr[100], int &arrLength) {
    bool addOrNot = true;
    do {
        
        AddArrayElement(arr, arrLength, ReadNumber());
       
        cout << "Do you want to add more numbers [0]:No, [1]:yes? ";
        cin >> addOrNot;

        cout << "\n\n";
    } while (addOrNot);
   
}

void PrintArray(int arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;

    InputUserNUmbersInArray(arr, arrLength);

    cout << "Array Length: " << arrLength << endl;

    cout << "Array Elements: ";
    PrintArray(arr, arrLength);

}