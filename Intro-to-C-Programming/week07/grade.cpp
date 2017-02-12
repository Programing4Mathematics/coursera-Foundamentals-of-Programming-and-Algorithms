#include <iostream>
using namespace std;

int main()
{
    int n, level;

    cin >> n;

    if (n >= 95 && n <= 100)
        level = 1;
    else if (n >= 90 && n < 95)
        level = 2;
    else if (n >= 85 && n < 90)
        level = 3;
    else if (n >= 80 && n < 85)
        level = 4;
    else if (n >= 70 && n < 80)
        level = 5;
    else if (n >= 60 && n < 70)
        level = 6;
    else if (n < 60)
        level = 7;

    cout << level << endl;

    return 0;
}