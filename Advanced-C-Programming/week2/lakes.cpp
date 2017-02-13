#include <iostream>
using namespace std;

int main()
{
    int a[4];
    int b[4];
    int flag = 0;
    // 0: 鄱阳湖; 1: 洞庭湖; 2: 太湖; 3: 洪泽湖
    
    for ( int i = 1; i <= 4 && flag == 0; i++ )
    {
        a[0] = i;
        for ( int j = 1; j <= 4 && flag == 0; j++ )
        {
            if ( j == i )
                continue;
            a[1] = j;
            for ( int k = 1; k <= 4 && flag == 0; k++ )
            {
                if ( k == i || k == j )
                    continue;
                a[2] = k;
                a[3] = 10 - i - j - k;
                
                b[0] = ( a[1] == 1 ) + ( a[3] == 4 ) + ( a[0] == 3 );
                b[1] = ( a[3] == 1 ) + ( a[1] == 4 ) + ( a[0] == 2 ) + ( a[2] == 3 );
                b[2] = ( a[3] == 4 ) + ( a[1] == 3 );
                b[3] = ( a[0] == 1 ) + ( a[2] == 4 ) + ( a[3] == 2 ) + ( a[1] == 3 );
                
                if ( b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1 )
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    
    for ( int i = 0; i < 4; i++ )
        cout << a[i] << endl;
    
    return 0;
}