#include <iostream>
using namespace std;

int main()
{
    int n, shiwei = 1, gewei = 0;
    
    cin >> n;
    
    for ( int i = 10; i <= n; i++ )
    {
        shiwei = i / 10;
        gewei = i % 10;
        
        if ( i % (shiwei + gewei) == 0 )
            cout << i << endl;
    }
    
    return 0;
}