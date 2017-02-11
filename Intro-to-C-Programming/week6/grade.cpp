#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max = 0;
    int grade;
    for(int i; i<n; i++){
        cin >> grade;
        if(grade>max) max = grade;
    }
    cout << max;
    return 0;
}