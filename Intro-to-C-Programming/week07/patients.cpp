#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, age;
    cin >> n;
    int first = 0, second = 0, third = 0, fourth = 0;
    for(int i=0; i<n; i++)
    {
        cin >> age;
        if(age<=18) first++;
        else if(age<=35) second++;
        else if(age<=60) third++;
        else fourth++;
    }
    cout<<fixed<<setprecision(2) << "1-18: " << (float) first*100/n << "%" << endl;
    cout<<fixed<<setprecision(2) << "19-35: " << (float) second*100/n << "%" << endl;
    cout<<fixed<<setprecision(2) << "36-60: " << (float) third*100/n << "%" << endl;
    cout<<fixed<<setprecision(2) << "60-: " << (float) fourth*100/n << "%" << endl;
}