#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    char a[100][100];
    char * b[100*100];
    int sum = 0;
    int sum_index = 0;
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
            cin >> a[i][j];
    }
    
    cin >> m;
    
    for ( int k = 0; k < m - 1; k++ )
    {
        sum_index = 0;
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                if ( a[i][j] == '@' )
                {
                    if ( i > 0 && a[i-1][j] == '.' )
                    {
                        b[sum_index] = &a[i-1][j];
                        sum_index = sum_index + 1;
                    }
                    if ( i < (n - 1) && a[i+1][j] == '.' )
                    {
                        b[sum_index] = &a[i+1][j];
                        sum_index = sum_index + 1;
                    }
                    if ( j > 0 && a[i][j-1] == '.' )
                    {
                        b[sum_index] = &a[i][j-1];
                        sum_index = sum_index + 1;
                    }
                    if ( j < (n - 1) && a[i][j+1] == '.' )
                    {
                        b[sum_index] = &a[i][j+1];
                        sum_index = sum_index + 1;
                    }
                }
            }
            
        }
        
        for ( int i = 0; i < sum_index; i++ )
        {
            if ( *b[i] == '.' )
                *b[i] = '@';
        }
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( a[i][j] == '@' )
                sum += 1;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}