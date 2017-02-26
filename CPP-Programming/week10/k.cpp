#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t, n, i, j, k;
	cin >> t;
	while(t--){
		cin >> n >> i >> j;
		k = pow(2, j) - pow(2, i+1);
		if (n & (1 << i))
            k = k | (1 << i);
        if (!(n & (1 << j)))
            k = k | (1 << j);
		cout << hex << k << endl;
	}
	return 0;
}