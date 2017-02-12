#include <iostream>
using namespace std;

int main()
{
    int N, K, payout, year;
    double yearly_inc, total;
    
    while ( cin >> N >> K )
    {
        payout = N;
        year = 1;
        total = 200.0;
        yearly_inc = (double)K / 100.0;
        
        while ( payout < total && year <= 20 )
        {
            payout = payout + N;
            total = total * (1.0 + yearly_inc);
            year++;
        }
        
        if ( year <= 20 )
            cout << year << endl;
        else
            cout << "Impossible" << endl;
    }
    
    return 0;
}