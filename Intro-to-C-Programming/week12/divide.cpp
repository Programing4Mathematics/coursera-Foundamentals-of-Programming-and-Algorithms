#include <iostream>
using namespace std;

int main()
{
    int N;
    
    while ( cin >> N )
    {
        int flag = 0;
        
        for ( int i = 3; i < 9; i += 2 )
        {
            if ( N % i == 0 )
            {
                cout << i << " ";
                flag += 1;
            }
        }
        
        if ( flag == 0 )
            cout << 'n' << endl;
        else
            cout << endl;
    }
    
    return 0;
}