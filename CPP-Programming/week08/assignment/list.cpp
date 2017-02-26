#include <list>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
void PrintList(const list<T> & lst) {
	int tmp = lst.size();
	if( tmp > 0 ) {
		typename list<T>::const_iterator i;
		i = lst.begin();
		for(i = lst.begin(); i != lst.end(); i++){
			cout << *i;
			if(tmp > 1)
				cout << " ";
		}
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	list <int> mylist[30000];
	int n, id, id1, id2, num;
	string command;																	
	cin >> n;
	while(n--){
		cin >> command;
		if (command == "new")
		{
			cin >> id;
			mylist[id] = list <int>();
		}
		else if (command == "add")
		{
			cin >> id >> num;
			mylist[id].push_back(num);
		}
		else if (command == "merge")
		{
			cin >> id1 >> id2;
			mylist[id1].merge(mylist[id2]);
		}
		else if (command == "unique")
		{
			cin >> id;
			mylist[id].sort();
			mylist[id].unique();
		}
		else if ( command == "out")
		{
			cin >> id;
			mylist[id].sort();
			PrintList(mylist[id]);
		}
	}	
	return 0;
}