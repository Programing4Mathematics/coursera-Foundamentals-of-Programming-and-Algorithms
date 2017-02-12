#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[5][5];
    int n, m;
    
    for ( int i = 0; i < 5; i++ )
    {
        for ( int j = 0; j < 5; j++ )
            cin >> a[i][j];
    }
    
    cin >> n >> m;
    
    if ( n >= 0 && n <= 4 && m >= 0 && m <= 4)
    {
        int temp = 0;
        
        for ( int i = 0; i < 5; i++ )
        {
            temp = a[m][i];
            a[m][i] = a[n][i];
            a[n][i] = temp;
        }
        
        for ( int i = 0; i < 5; i++ )
        {
            for ( int j = 0; j < 5; j++ )
                cout << setw(4) << a[i][j];
            
            cout << endl;
        }
    }
    else
        cout << "error" << endl;
    
    return 0;
}