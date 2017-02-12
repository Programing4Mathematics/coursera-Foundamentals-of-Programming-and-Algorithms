#include <iostream>
using namespace std;
int main()
{
    int largestOdd = 1, smallestEven = 100;
    int num;
    for(int i; i<6; i++){
        cin >> num;
        if(num%2==0 && num<smallestEven) smallestEven = num;
        if(num%2==1 && num>largestOdd) largestOdd = num;
    }
    int diff = largestOdd - smallestEven;
    if(diff<0) diff = -diff;
    cout << diff;
    return 0;
}