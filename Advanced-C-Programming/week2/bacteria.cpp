#include <iostream>
using namespace std;

float abs_x(float);

int main(void)
{
    int n;
    float dis_max = 0.0;
    float dis = 0.0;
    int dis_index = 0;
    float a[101];
    int b[101];
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        int num;
        float before, after;
        float rate;
        cin >> num >> before >> after;
        rate = (after - before) / before;
        a[i] = rate;
        b[i] = num;
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = i + 1; j < n; j++ )
        {
            if ( a[i] < a[j] )
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
    
    for ( int i = 0; i < n - 1; i++ )
    {
        dis = abs_x(a[i + 1] - a[i]);
        if ( dis > dis_max )
        {
            dis_max = dis;
            dis_index = i;
        }
    }
    
    cout << (dis_index + 1) << endl;
    for ( int i = dis_index; i >= 0; i-- )
        cout << b[i] << endl;
    
    cout << (n - dis_index - 1) << endl;
    for ( int i = n - 1; i > dis_index; i-- )
        cout << b[i] << endl;
    
    return 0;
}

float abs_x(float dis)
{
    if ( dis < 0 )
        dis = 0 - dis;
    
    return dis;
}