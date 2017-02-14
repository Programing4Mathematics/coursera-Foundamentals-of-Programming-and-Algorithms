#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int input[100][100] = {0};
	int k, m, n; //m行n列
	int sum = 0;
	int *p = NULL, *q = NULL;
	cin >> k;
	while(k--){
		sum = 0;
		cin >> m >> n;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> input[i][j];
		if (m == 1 || n == 1){
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					sum += input[i][j];
			cout << sum << endl;
		}
		else{
			p = input[0];
			q = input[m-1];
			for (int i = 0; i < n; ++i)
			{
				sum += *p++;
				sum += *q++;
			}
			if(m > 2){
				p = input[0];
				q = &input[0][n-1];
				for (int i = 1; i < m-1; ++i){
					sum += *(p + i * 100);
					sum += *(q + i * 100);
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}