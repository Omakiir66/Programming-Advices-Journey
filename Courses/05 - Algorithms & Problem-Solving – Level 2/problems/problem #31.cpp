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
void ReadArray(int arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arr[i] = i + 1;
    }
}
void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void ShuffleArray(int arr[100], int arrLength) {
    
    for (int i = 0; i < arrLength; i++) {
        swap(arr[RandomNumber(1, arrLength) -1], arr[RandomNumber(1, arrLength) -1 ]);
       
    }
}

void PrintArray(int arr[100], int Length) {

    for (int i = 0; i < Length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main()
{
   
    int arr1[100];
    int arrLength = ReadPositiveNumber("please enter how many elements: ");

    ReadArray(arr1, arrLength);
    
    cout << "\n\nArray Elements before shuffle: \n";
    PrintArray(arr1, arrLength);

    ShuffleArray(arr1, arrLength);

    cout << "\n\nArray Elements After shuffle: \n";
    PrintArray(arr1, arrLength);


}