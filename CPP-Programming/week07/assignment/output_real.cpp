#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	double number;
	cin >> number;
	cout << fixed << setprecision(5) << number << endl;
	cout << fixed << setprecision(7) << scientific << number;
	return 0;
}