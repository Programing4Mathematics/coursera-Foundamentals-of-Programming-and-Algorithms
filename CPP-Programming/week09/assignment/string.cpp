#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
using namespace std;
const int kMaxNum = 20;
string str[kMaxNum];
int number = 0;
char* strItoa = new char[101];
int GotNXL();
string GotS();
string copy();
string add();
int find();
int rfind();
void insert();
void reset();
void print();
void printall();


int GotNXL() {
	string NXL;
	int nxl;
	cin >> NXL;
	if (NXL == "find")
		nxl = find();
	else if (NXL == "rfind")
		nxl = rfind();
	else
		nxl = atoi(NXL.c_str());
	return nxl;
}

string GotS() {
	string S, result;
	cin >> S;
	result = S;
	if (S == "add")
		result = add();
	else if (S == "copy")
		result = copy();
	return result;
}

string copy() {
	string result;
	int n, x, l;
	n = GotNXL();
	x = GotNXL();
	l = GotNXL();
	result = str[n - 1].substr(x, l);
	return result;
}

string add() {
	string S1, S2;
	S1 = GotS();
	S2 = GotS();
	for (int i = 0; i < S1.size(); i++)
	{
		if (S1.at(i) < '0' || S1.at(i) > '9')
		{
			return  S1 + S2;
		}
	}
	for (int i = 0; i < S2.size(); i++)
	{
		if (S2.at(i) < '0' || S2.at(i) > '9')
		{
			return S1 + S2;
		}
	}
	long a = atoi(S1.c_str());
	long b = atoi(S2.c_str());
	if (a >= 0 && a <= 99999 && b >= 0 && b <= 99999)
	{
		long c = a + b;
		sprintf(strItoa, "%d", c);
		return strItoa;
	}
	else
		return S1 + S2;
}

int find() {
	string S;
	int n, pos;
	S = GotS();
	n = GotNXL();
	pos = str[n - 1].find(S);
	if (pos == string::npos)
		return str[n - 1].size();
	else
		return pos;
}

int rfind() {
	string S;
	int n, pos;
	S = GotS();
	n = GotNXL();
	pos = str[n - 1].rfind(S);
	if (pos == string::npos)
		return str[n - 1].size();
	else
		return pos;
}

void insert() {
	string S;
	int n, x;
	S = GotS();
	n = GotNXL();
	x = GotNXL();
	str[n - 1].insert(x, S);
}

void reset() {
	string S;
	int n;
	S = GotS();
	n = GotNXL();
	str[n - 1] = S;
}

void print() {
	int n;
	n = GotNXL();
	cout << str[n - 1] << endl;
}

void printall() {
	for (int i = 0; i < number; ++i)
		cout << str[i] << endl;
}


int main(int argc, char const *argv[])
{
	string order;
	cin >> number;
	for (int i = 0; i < number; ++i)
	{
		cin >> str[i];
	}
	while (1) {
		cin >> order;
		if (order == "over")
			break;
		else if (order == "insert")
			insert();
		else if (order == "reset")
			reset();
		else if (order == "print")
			print();
		else if (order == "printall")
			printall();
		else if (order == "insert")
			insert();
	}
	return 0;
}