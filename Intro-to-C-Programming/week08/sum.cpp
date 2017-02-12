#include <iostream>
using namespace std;

int main()
{
    int a[6] = {0};
    int sum = 0;
    
    for ( int i = 0; i < 6; i++ )
    {
        cin >> a[i];
        
        if ( i > 0 && a[i] < a[0] )
        {
            sum += a[i];
        }
    }
    
    cout << sum << endl;
    
    return 0;
}