#include <iostream>
#include <iomanip>
using namespace std;

int findtypenum(char, char[]);

int main(void)
{
    double a[4] = {0.0, 0.0, 0.0, 0.0};
    float typesum[3] = {0.0, 0.0, 0.0};
    char type[3] = {'A', 'B', 'C'};
    
    for ( int i = 0; i < 3; i++ )
    {
        int p, count;
        cin >> p >> count;
        
        for ( int j = 0; j < count; j++ )
        {
            char typechar;
            int typenum;
            float typemoney;
            
            cin >> typechar >> typemoney;
            typenum = findtypenum(typechar, type);
            
            typesum[typenum] += typemoney;
            a[p] += typemoney;
        }
    }
    
    for ( int i = 1; i < 4; i++ )
    {
        cout << i << " " << fixed << setprecision(2) << a[i] << endl;
    }
    for ( int i = 0; i < 3; i++ )
    {
        cout << type[i] << " " << typesum[i] << endl;
    }
    
    return 0;
}

int findtypenum(char typechar, char type[])
{
    int i = 0;
    for ( ; i < 3; i++ )
    {
        if ( typechar == type[i] )
            break;
    }
    
    return i;
}