#include <iostream>
using namespace std;

int main()
{
    int n, k, a[1000];
    
    cin >> n >> k;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = i; j < n; j++ )
        {
            if ( (a[i] + a[j]) == k )
            {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "no" << endl;
    
    return 0;
}