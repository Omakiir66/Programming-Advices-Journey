
#include <iostream>
using namespace std;

void PrintHeader() {
    cout << "\n\n\t\t\t Multiplication Table From 1 To 10\n\n";
    for (int i = 1; i < 11;i++) {
        cout << "\t" << i;
    }
    cout << "\n\n";
    cout << "------------------------------------------------------------------------------------\n";
}

string columnSperator(short number) {

    if (number < 10)
        return "   |";
    else
        return"  |";
   
}

void PrintMultiplicationTable() {
    PrintHeader();
    for (int i = 1;i < 11;i++)
    {   
        cout << " " << i << columnSperator(i)<<"\t";

        for (int j = 1; j < 11;j++) {
            cout<< i * j <<"\t";
        }
        cout << "\n";
    }
}
int main()
{
  
    PrintMultiplicationTable();
}
