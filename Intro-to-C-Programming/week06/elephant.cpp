#include <iostream>
using namespace std;
int main()
{
    float pi = 3.14159;
    int h, r;
    cin >> h >> r;
    float v = h*r*r*pi;
    cout <<  int(20000 / v) + 1;
    return 0;
}