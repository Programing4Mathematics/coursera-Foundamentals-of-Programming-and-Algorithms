#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[100];
    int flag = 0;
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
        
        if ( a[i] == i )
        {
            cout << a[i] << endl;
            flag = 1;
            break;
        }
    }
    
    if ( flag == 0 )
        cout << "N" << endl;
    
    return 0;
}