#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int a[2];
    char s;
    
    cin >> a[0] >> a[1] >> s;
    
    switch(s)
    {
        case '+':
            cout << a[0] + a[1] << endl;
            break;
        case '-':
            cout << a[0] - a[1] << endl;
            break;
        case '*':
            cout << a[0] * a[1] << endl;
            break;
        case '/':
            if ( a[1] == 0 )
                cout << "Divided by zero!" << endl;
            else
                cout << a[0] / a[1] << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
            break;
    }
    
    return 0;
}