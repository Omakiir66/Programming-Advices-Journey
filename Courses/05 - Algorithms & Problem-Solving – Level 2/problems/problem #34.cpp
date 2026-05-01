#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

 int ReadPositiveNumber(string message) {

    int number;
    do {

     cout << message;
        cin >> number;
    }   while (number <= 0);
        return number;
}

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
int FindElementInArray(int arr[100],int arrLength, int NumberToSearch) {
    for (int i = 0; i < arrLength; i++) 
    {
        if (NumberToSearch == arr[i])
            return i;
       
    }
    return -1;

}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100], areLength;

    FillArrayWithRandomElements(arr, areLength);

    cout << "Array Elements: ";
    PrintArray(arr, areLength);

    int NumberToSearch = ReadPositiveNumber("\nplease enter a number to search for: ");

    cout << "Number you are looking for: " << NumberToSearch << endl;
    if (FindElementInArray(arr, areLength, NumberToSearch) != -1) {
        cout << "The number found at position: " << FindElementInArray(arr, areLength, NumberToSearch) << endl;
        cout << "the number found its order: " << FindElementInArray(arr, areLength, NumberToSearch) + 1 << endl;
    }
    else {
        cout << "The number is not found :-(" << endl;
    }




}