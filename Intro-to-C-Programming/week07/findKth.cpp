#include <iostream>
using namespace std;

int main()
{
    int n, k, a[1000], temp;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] > a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    cout << a[k - 1] << endl;

    return 0;
}