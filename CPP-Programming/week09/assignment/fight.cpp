#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	typedef map<int, int> mmid;  
	mmid member;
	int n, id, power;
	int id1, id2, p1 = 0, p2 = 0;
	mmid::iterator it;
	member[1000000000] = 1;
	pair<mmid::iterator, bool> result;
	cin >> n;
	while(n--){
		scanf("%d %d", &id, &power);
		result = member.insert(mmid::value_type(power, id));
		mmid::iterator i = result.first;
		if (i == member.begin())
        {
            i++;
            printf("%d %d\n", id, i->second);
        }else if (i == member.end())
        {
        	i--;
        	cout << id << ' ' << i->second << endl;
        }else{
        	i--;
        	id1 = i->second;
        	p1 = i->first;
        	i++;
        	i++;
        	id2 = i->second;
        	p2 = i->first;
        	if (power - p1 <= p2- power)
        		printf("%d %d\n", id, id1);
        	else
        		printf("%d %d\n", id, id2);
        }
	}

	return 0;
}