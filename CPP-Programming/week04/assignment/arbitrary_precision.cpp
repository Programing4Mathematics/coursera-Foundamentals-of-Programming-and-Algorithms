#include <iostream>
#include <string>
using namespace std;
string add_int(string, string);
string sub_int(string, string);
string mul_int(string, string);
string div_int(string, string);
string mod_int(string, string);
string divide_int(string, string, int);

inline int compare(string s1, string s2)
{
	if (s1.size() < s2.size())
		return -1;
	else if (s1.size() > s2.size())
		return 1;
	else
		return s1.compare(s2);
}
string add_int(string s1, string s2)
{
	if (s1 == "0")
		return s2;
	if (s2 == "0")
		return s1;
	if (s1[0] == '-')
	{
		if (s2[0] == '-')
		{
			return "-" + add_int(s1.erase(0, 1), s2.erase(0, 1));  
		}
		else
		{
			return sub_int(s2, s1.erase(0, 1));  
		}
	}
	if (s2[0] == '-')
	{
		return sub_int(s1, s2.erase(0, 1)); 
	}
	string::size_type i, size1, size2;
	size1 = s1.size();
	size2 = s2.size();
	if (size1 < size2)
	{
		for (i = 0; i < size2 - size1; i++)  
			s1 = "0" + s1;
	}
	else
	{
		for (i = 0; i < size1 - size2; i++)   
			s2 = "0" + s2;
	}

	int n1, n2;
	n2 = 0;
	size1 = s1.size();
	size2 = s2.size();
	string res;
	for (i = size1 - 1; i != 0; i--)  
	{
		n1 = (s1[i] - '0' + s2[i] - '0' + n2) % 10;  
		n2 = (s1[i] - '0' + s2[i] - '0' + n2) / 10; 
		res = char(n1 + '0') + res;
	}
	n1 = (s1[0] - '0' + s2[0] - '0' + n2) % 10;
	n2 = (s1[0] - '0' + s2[0] - '0' + n2) / 10;
	res = char(n1 + '0') + res;

	if (n2 == 1)
		res = "1" + res;

	return res;
}
string sub_int(string s1, string s2)
{
	if (s2 == "0")
		return s1;
	if (s1 == "0")
	{
		if (s2[0] == '-')
			return s2.erase(0, 1);
		return "-" + s2;
	}

	if (s1[0] == '-')
	{
		if (s2[0] == '-')
		{
			return sub_int(s2.erase(0, 1), s1.erase(0, 1));  
		}
		return "-" + add_int(s1.erase(0, 1), s2);   
	}

	if (s2[0] == '-')
		return add_int(s1, s2.erase(0, 1));  

	string::size_type i, size1, size2;
	size1 = s1.size();
	size2 = s2.size();
	if (size1 < size2)
	{
		for (i = 0; i < size2 - size1; i++)   
			s1 = "0" + s1;
	}
	else
	{
		for (i = 0; i < size1 - size2; i++)  
			s2 = "0" + s2;
	}
	int t = s1.compare(s2);

	if (t < 0)   
		return "-" + sub_int(s2, s1);

	if (t == 0)
		return "0";

	string res;
	string::size_type j;
	for (i = s1.size() - 1; i != 0; i--)
	{
		if (s1[i] < s2[i])   
		{
			j = 1;
			while (s1[i - j] == '0')
			{
				s1[i - j] = '9';
				j++;
			}
			s1[i - j] -= 1;
			res = char(s1[i] + ':' - s2[i]) + res;
		}
		else
		{
			res = char(s1[i] - s2[i] + '0') + res;
		}
	}
	res = char(s1[0] - s2[0] + '0') + res;
	res.erase(0, res.find_first_not_of('0'));
	return res;
}
string mul_int(string s1, string s2)
{
	if (s1 == "0" || s2 == "0")
		return "0";
	int sign = 1;
	if (s1[0] == '-')
	{
		sign *= -1;
		s1.erase(0, 1);
	}
	if (s2[0] == '-')
	{
		sign *= -1;
		s2.erase(0, 1);
	}

	string::size_type size1, size2;
	string res, temp;
	size1 = s1.size();
	size2 = s2.size();
	if (size1 < size2)
	{
		temp = s1;
		s1 = s2;
		s2 = temp;
		size1 = s1.size();
		size2 = s2.size();
	}

	int i, j, n1, n2, n3, t;
	for (i = size2 - 1; i >= 0; i--)
	{
		temp = "";
		n1 = n2 = n3 = 0;
		for (j = 0; j < size2 - 1 - i; j++) temp = "0" + temp;
		n3 = s2[i] - '0';
		for (j = size1 - 1; j >= 0; j--)
		{
			t = (n3*(s1[j] - '0') + n2);
			n1 = t % 10;  
			n2 = t / 10;  
			temp = char(n1 + '0') + temp;
		}
		if (n2)
			temp = char(n2 + '0') + temp;
		res = add_int(res, temp);
	}
	if (sign == -1)
		return "-" + res;
	return res;
}
string divide_int(string s1, string s2, int flag)  
{
	string quotient, residue;
	if (s2 == "0")
	{
		quotient = residue = "error";
		if (flag == 1)
			return quotient;
		else
			return residue;
	}
	if (s1 == "0")
	{
		quotient = residue = "0";
		if (flag == 1)
			return quotient;
		else
			return residue;
	}
	int sign1, sign2;
	sign1 = sign2 = 1;
	if (s1[0] == '-')
	{
		sign1 *= -1;
		sign2 = -1;
		s1.erase(0, 1);
	}
	if (s2[0] == '-')
	{
		sign1 *= -1;
		s2.erase(0, 1);
	}

	if (compare(s1, s2) < 0)
	{
		quotient = "0";
		residue = s1;
	}
	else if (compare(s1, s2) == 0)
	{
		quotient = "1";
		residue = "0";
	}
	else
	{
		string temp;
		string::size_type size1, size2;
		size1 = s1.size();
		size2 = s2.size();
		int i;
		if (size2 > 1) temp.append(s1, 0, size2 - 1);

		for (i = size2 - 1; i < size1; i++)
		{
			temp = temp + s1[i];
			for (char c = '9'; c >= '0' ; c--)
			{
				string t = mul_int(s2, string(1, c));

				string s = sub_int(temp, t);

				if (s == "0" || s[0] != '-')
				{
					temp = s;
					quotient = quotient + c;
					break;
				}
			}
		}
		residue = temp;
	}
	quotient.erase(0, quotient.find_first_not_of('0'));
	residue.erase(0, residue.find_first_not_of('0'));
	if (sign1 == -1)
	{
		quotient = "-" + quotient;
	}
	if (sign2 == -1)
	{
		if (residue.empty())
			residue = "0";
		else
			residue = "-" + residue;
	}

	if (flag == 1) return quotient;
	else return residue;
}
string div_int(string s1, string s2)
{
	return divide_int(s1, s2, 1);
}
string mod_int(string s1, string s2)
{
	return divide_int(s1, s2, 0);
}
int main(void)
{
	string s1, s2;
	char op;
	while (cin >> s1 >> op >> s2)
	{
		switch (op)
		{
		case '+':cout << add_int(s1, s2) << endl; break;
		case '-':cout << sub_int(s1, s2) << endl; break;
		case '*':cout << mul_int(s1, s2) << endl; break;
		case '/':cout << div_int(s1, s2) << endl; break;
		case '%':cout << mod_int(s1, s2) << endl; break;
		default:
			cout << "The operator is error!" << endl; break;
		}
	}
	return 0;
}