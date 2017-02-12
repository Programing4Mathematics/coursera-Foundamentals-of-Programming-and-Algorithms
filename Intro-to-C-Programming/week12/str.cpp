#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    char str[10];
    char strst[15];
    char substr[4];
    
    while ( cin >> str >> substr)
    {
        char max = 0;
        int max_i = 0;
        
        for ( int i = 0; str[i] != '\0' && i < 11; i++ )
        {
            if ( str[i] > max )
            {
                max = str[i];
                max_i = i + 1;
            }
        }
        
        int i = 0;
        
        for ( ; i < max_i; i++ )
            strst[i] = str[i];
        for ( int j = 0; substr[j] != '\0' && j < 4; j++)
            strst[i++] = substr[j];
        
        for ( int j = max_i; str[j] != '\0' && j < 11; j++)
            strst[i++] = str[j];
        
        cout << strst << endl;
        
        for ( int i = 0; i < 11; i++ )
            str[i] = '\0';
        for ( int i = 0; i < 4; i++ )
            substr[i] = '\0';
        for ( int i = 0; i < 15; i++ )
            strst[i] = '\0';
    }
    
    return 0;
}