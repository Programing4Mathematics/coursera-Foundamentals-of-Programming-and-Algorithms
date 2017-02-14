#include "iostream"
using namespace std;
int inbound(int row, int col, int i, int j){
	return (i >= 0) && (i < row) && (j >= 0) && (j < col); 
}

int main(int argc, char const *argv[])
{
	int row, col;
	cin >> row >> col;
	int input[row][col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> input[i][j];

	for (int i = 0; i < col; ++i)
	{
		int rowtemp = 0;
		int coltemp = i;
		while(inbound(row, col, rowtemp, coltemp)){
			cout << input[rowtemp][coltemp] << endl;
			rowtemp++;
			coltemp--;
		}
	}

	if (row > 1)
	{
		for (int i = 1; i < row; ++i)
		{
			int rowtemp = i;
			int coltemp = col - 1;
			while(inbound(row, col, rowtemp, coltemp)){
				cout << input[rowtemp][coltemp] << endl;
				rowtemp++;
				coltemp--;
		}
		}
	}

	return 0;
}