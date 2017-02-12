#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[6] = {100, 50, 20, 10, 5, 1};
    int b[6] = {0};
    int i = 0;

    cin >> n;

    while (n > 0)
    {
        b[i] = n / a[i];
        n = n % a[i];
        i++;
    }

    for (int j = 0; j < 6; j++)
        cout << b[j] << endl;

    return 0;
}