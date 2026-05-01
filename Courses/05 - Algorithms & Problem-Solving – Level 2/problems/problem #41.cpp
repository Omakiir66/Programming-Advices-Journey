#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void FillArray(int arr[100], int& arrLength) {
  /*  arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;*/
    cout << "please enter the number of array: \n";
    cin >> arrLength;
    cout << "\n\nplease enter elements of array: \n";
    for (int i = 0; i < arrLength; i++) {
        cout << "array[" << i << "]:";
        cin >> arr[i];
    }
    
}

bool IsPalindromeArray(int arr[100], int arrLength) {
    
    for (int i = 0;i < arrLength /2;i++) {

        if (arr[i] != arr[arrLength - 1 - i])
            return false;
    }
    return true;


}

void PrintArray(int arr[100], int Length) {

    for (int i = 0; i < Length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int arrSource[100], SourceLength = 0;

    FillArray(arrSource, SourceLength);

    cout << "\n\nArray Elements: \n";
    PrintArray(arrSource, SourceLength);

    if (IsPalindromeArray(arrSource, SourceLength))
        cout << "\nYes, array is Palindrome.\n";
    else
        cout << "\nNo, array is NOT Palindrome.\n";

}