#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    double walk, bike;
    int result[3] = {0};
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> temp;
        
        walk = (double)temp / 1.2;
        bike = (double)temp / 3.0 + 50.0;
        
        if ( walk > bike )
            result[i] = 0;
        else if ( bike > walk )
            result[i] = 1;
        else
            result[i] = 2;
    }
    
    for ( int i = 0; i < n; i++ )
    {
        if ( result[i] == 0 )
            cout << "Bike" << endl;
        else if ( result[i] == 1 )
            cout << "Walk" << endl;
        else
            cout << "All" << endl;
    }
    
    return 0;
}