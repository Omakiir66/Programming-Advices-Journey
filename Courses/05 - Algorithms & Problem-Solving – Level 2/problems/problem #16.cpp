
#include <iostream>
#include <cmath>
using namespace std;



void PrintWordsFromAAAToZZZ() {
    string word = "";
    for (short i = 65; i <= 90; i++) 
    {

        for (short j = 65; j <= 90; j++) 
        {

            for (short k = 65; k <= 90; k++) 
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << word << endl;

                word = "";
            
            }
        }
        cout << "----------------------\n";
        
    }
    
}


int main()
{

    PrintWordsFromAAAToZZZ();

}