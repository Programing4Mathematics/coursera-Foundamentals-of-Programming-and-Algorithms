#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
	multiset<int> intset;
	set<int> history;
	int n, x;
	string command;
	cin >> n;
	while(n--){
		cin >> command;
		if (command == "add")
		{
			cin >> x;
			intset.insert(x);
			history.insert(x);
			cout << intset.count(x) << endl;  
		}else if (command == "del")
		{
			cin >> x;
			cout << intset.count(x) << endl; 
			intset.erase(x);
		}
		else if (command == "ask")
		{
			cin >> x;
			if(history.count(x))
				cout << "1" << " ";   
			else
				cout << "0" << " ";
			cout << intset.count(x) << endl;  
		}

	}
	return 0;
}