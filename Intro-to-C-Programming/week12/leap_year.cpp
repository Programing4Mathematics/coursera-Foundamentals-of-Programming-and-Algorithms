#include <iostream>
using namespace std;

int main()
{
    int N;
    bool leap = false;
    
    cin >> N;
    
    if ( N % 4 == 0 )
    {
        leap = true;
        if ( (N % 100 == 0) && (N % 400 != 0) )
            leap = false;
        
        if ( N % 3200 == 0 )
            leap = false;
    }
    
    if ( leap )
        cout << 'Y' << endl;
    else
        cout << 'N' << endl;
    
    return 0;
}