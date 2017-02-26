#include <cstdio> 
#include <cmath>  
#include <set>  
#include <iostream>
using namespace std; 

bool IsPrime(int x){
	for (int i = 2; i <= sqrt(x); i++)  
    {  
        if (x % i == 0)  
            return false;
    }  
    return true;  
}

template <class T>
void Print(T first, T last)
{ 
	for(;first != last ; ++first) cout << * first << " ";
	cout << endl;
}

int FactorNum(int x){
	int temp, result = 0;
	for (int i = 2; i <= sqrt(x); i++)  
	    if ((x % i) == 0){
	    	if(IsPrime(i)) 
	    		result++;
	    	temp = x / i;
	    	if (IsPrime(temp) && (i != temp))
	    		result++;
	    }
    return result;  
}

class MyLess{
public:
	bool operator()( const int & x, const int & y){
		if (FactorNum(x) > FactorNum(y))
			return true;
		else if (FactorNum(x) == FactorNum(y))
		{
			return (x > y);
		}
		else 
			return false;
	}
};

int main(int argc, char const *argv[])
{
	set<int, MyLess> intset;
	int num, x, min, max; 
	scanf("%d", &num); 
	while(num--){
		for (int i = 0; i < 10; ++i)
		{
			scanf("%d", &x);
			intset.insert(x);
			
		}
		max = *(intset.begin());  
	    min = *(intset.rbegin()); 
	    intset.erase(max);  
	    intset.erase(min);
	    printf("%d %d\n",max, min);
	}
	return 0;
}