#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 0;
    int a[100][100];
    int sum = 0;
    
    cin >> N;
    
    for ( int i = 0; i < N; i++ )
    {
        for ( int j = 0; j < N; j++ )
        {
            cin >> a[i][j];
        }
    }
    
    for ( int i = 1; i < N - 1; i++ )
    {
        for ( int j = 1; j < N - 1; j++ )
        {
            int top = a[i-1][j];
            int left = a[i][j-1];
            int down = a[i + 1][j];
            int right = a[i+1][j];
            
            if ( (top - a[i][j]) >= 50 && (left - a[i][j]) >= 50 && (right - a[i][j]) >= 50 && (down - a[i][j]) >= 50 )
                sum++;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}