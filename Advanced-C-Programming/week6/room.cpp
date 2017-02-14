#include "iostream"
#include "string.h"
#include <iomanip>  
using namespace std;
int main(int argc, char const *argv[])
{
	int number;
	double threshold;
	cin >> number >> threshold;
	char no[number][4];
	double serious[number];
	char tempno[4];
	double tempserious;
	int tempi = 0;
	for (int i = 0; i < number; ++i)
	{	
		cin >> tempno;
		cin >> tempserious;
		if (tempserious > threshold)
		{
			strcpy(no[tempi], tempno);
			serious[tempi] = tempserious;
			tempi++;
		}
	}
	if (tempi == 0)
	{
		cout << "None.";
	}
	else{
		for(int i =0 ; i < tempi - 1; ++i) {  
	        for(int j = 0; j < tempi - i - 1; ++j) {  
	            if(serious[j] < serious[j+1])
	            {  
	                double tmp = serious[j]; serious[j] = serious[j+1];  serious[j+1] = tmp;
	                char tempchar[4];
	                strcpy(tempchar, no[j]); strcpy(no[j],no[j+1]); strcpy(no[j+1], tempchar);
	            }  
	        }  
	    }
	    cout.setf(ios::fixed);    
		for (int i = 0; i < tempi; ++i)
		{
			cout << no[i] << " " << setprecision(1) << serious[i] << endl;
		}
	}

	return 0;
}