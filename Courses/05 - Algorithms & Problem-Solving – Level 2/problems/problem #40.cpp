#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void FillArray(int arr[100], int& arrLength) {
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}
void AddArrayElement(int arr[100], int& arrLength, int  Number) {
    arr[arrLength] = Number;
    arrLength++;
}


void PrintArray(int arr[100], int Length) {

    for (int i = 0; i < Length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int FindElementInArray(int arr[100], int arrLength, int NumberToSearch) {
    for (int i = 0; i < arrLength; i++)
    {
        if (NumberToSearch == arr[i])
            return i;

    }
    return -1;

}
bool IsNumberInArray(int arr[100], int arrLength, int NumberToSearch) {

    return FindElementInArray(arr, arrLength, NumberToSearch) != -1;

}

void CopyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length) {

    

    for (int i = 0; i < arrLength; i++) {
        if(!IsNumberInArray(arrDestination, arr2Length, arrSource[i]))
            AddArrayElement(arrDestination, arr2Length, arrSource[i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arrSource[100], arrDest[100], SourceLength = 0, DestLength = 0;

    FillArray(arrSource, SourceLength);

    cout << "Array 1 Elements: \n";
    PrintArray(arrSource, SourceLength);

    CopyDistinctNumbers(arrSource, arrDest, SourceLength, DestLength);

    cout << "\n\nArray 2 Distinct Elements: \n";
    PrintArray(arrDest, DestLength);
}