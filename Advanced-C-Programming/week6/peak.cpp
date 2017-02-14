#include "iostream"
using namespace std;
int m, n;
int inbound(int i, int j){
	return (i >= 0) && (i < m) && (j >= 0) && (j < n);
}

int main(int argc, char const *argv[])
{
	cin >> m >> n;
	int input[m][n];
	int maxtemp= -1;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> input[i][j];
	for (int i = 0; i < m; ++i) //优先上下检索
		for (int j = 0; j < n; ++j){
			maxtemp = -1;
			if (inbound(i-1, j) && input[i-1][j] > maxtemp)
				maxtemp = input[i-1][j];
			if (inbound(i+1, j) && input[i+1][j] > maxtemp)
				maxtemp = input[i+1][j];
			if (inbound(i, j-1) && input[i][j-1] > maxtemp)
				maxtemp = input[i][j-1];
			if (inbound(i, j+1) && input[i][j+1] > maxtemp)
				maxtemp = input[i][j+1];
			if (input[i][j] >= maxtemp)
				cout << i << " " << j << endl;
		}
	return 0;
}