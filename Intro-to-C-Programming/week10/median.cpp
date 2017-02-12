#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    int a[15000];
    int mid;
    
    while ( true )
    {
        cin >> N;
        
        if ( N == 0 )
            break;
        
        for ( int i = 0; i < N; i++ )
            cin >> a[i];
        
        for ( int i = 0; i < N / 2 + 1; i++ )
        {
            for ( int j = i + 1; j < N; j++ )
            {
                if ( a[i] < a[j] )
                {
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
        
        if ( N % 2 == 0 )
            mid = (a[N/2] + a[N/2 - 1]) / 2;
        else
            mid = a[N/2];
        
        cout << mid << endl;
    }
    
    return 0;
}