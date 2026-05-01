#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
    return  rand() % (To - From + 1) + From ;
}


int main()
{
    srand((unsigned)time(NULL));

    //cout << rand() %10 << endl;
    //cout << rand() %10 << endl;
    
    cout << RandomNumber(10, 100) << endl;
    cout << RandomNumber(10, 100) << endl;
    cout << RandomNumber(10, 100) << endl;


}