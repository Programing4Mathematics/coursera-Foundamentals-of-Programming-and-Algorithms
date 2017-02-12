#include <iostream>
using namespace std;

int main()
{
    int L, M;   // 1 <= L <= 10000 和 1 <= M <= 100
    int sum = 0;
    int b[10000] = {0};
    
    cin >> L >> M;
    
    for ( int i = 0; i < M; i++ )
    {
        int begin, end;
        cin >> begin >> end;
        
        for ( int k = begin; k <= end; k++ )
        {
            if ( b[k] != 1 )
                b[k] = 1;
        }
    }
    
    for ( int i = 0; i <= L; i++ )
    {
        if ( b[i] == 0 )
            sum += 1;
    }
    
    cout << sum << endl;
    
    return 0;
}