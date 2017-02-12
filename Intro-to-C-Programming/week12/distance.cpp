#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n; // n >= 2
    float a[1000][2];
    double max_dis = 0.0;
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i][0];
        cin >> a[i][1];
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = i + 1; j < n; j++ )
        {
            double dis_x = a[j][0] - a[i][0];
            double dis_y = a[j][1] - a[i][1];
            double dis = sqrt(dis_x * dis_x + dis_y * dis_y);
            if ( dis > max_dis )
                max_dis = dis;
        }
    }
    
    cout << fixed << setprecision(4) << max_dis << endl;
    
    return 0;
}