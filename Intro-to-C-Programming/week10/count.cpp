#include <iostream>
using namespace std;

int main()
{
    char a[80];
    int count[5] = {0};
    
    cin.getline(a, 80);
    
    for ( int i = 0; i < 80; i++ )
    {
        switch ( a[i] )
        {
            case 'a':
                count[0]++;
                break;
            case 'e':
                count[1]++;
                break;
            case 'i':
                count[2]++;
                break;
            case 'o':
                count[3]++;
                break;
            case 'u':
                count[4]++;
                break;
        }
    }
    
    for ( int i = 0; i < 5; i++ )
    {
        if ( i != 4 )
            cout << count[i] << " ";
        else
            cout << count[i] << endl;
    }
    
    return 0;
}