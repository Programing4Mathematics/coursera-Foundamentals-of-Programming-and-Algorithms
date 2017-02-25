#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	int number;
	cin >> number;
	cout << hex << number << endl;
	cout << dec << setw(10) << setfill ('0') << number << endl;
	return 0;
}