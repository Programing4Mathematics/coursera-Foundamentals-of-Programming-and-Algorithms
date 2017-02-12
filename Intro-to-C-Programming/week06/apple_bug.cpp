#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int left = n - y/x;
    if(y%x!=0) left--;
    if(left<0) left = 0;
    cout << left;
    return 0;
}