
#include <iostream>
#include <cmath>
using namespace std;

string ReadPassword(string message) {
    string pass = "";
    cout << message << endl;
    cin >> pass;

    return pass;

}


bool CheckWordsFromAAAToZZZ(string pass) {
    string word = "";
    int counter = 1;

    for (short i = 65; i <= 90; i++)
    {

        for (short j = 65; j <= 90; j++)
        {

            for (short k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                
                cout << "Trial [" << counter << "]:" << word << endl;
              
                if (word == pass) {
                    cout << "\nPassword is " << word << endl;
                    cout << "Found after " << counter << " Trial(s).\n";
                    return true;
                }

                counter++;

                word = "";

            }
        }
        cout << "----------------------\n";

    }
    

}


int main()
{

    CheckWordsFromAAAToZZZ(ReadPassword("please enter a 3-letter capital password: "));

}