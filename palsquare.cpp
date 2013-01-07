/*
ID: yyjoyce1
PROG: palsquare
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string convertBase(int x, int b)
{
	//Convert x from base 10 to base b.
	string y;
	while (x>0)
	{
		char dig = ('0' + x % b);
		if (dig > '9')
			dig = dig + 'A' - '9' - 1;
		y = dig + y;
		x = x / b;
	}
	return y;
}

bool palindrome(string x)
{
	//Return true iff x is a palindrome.

	if (x.length() == 1 || x.length() == 0)
		return true;
	else
	{
		if (x[0] == x[x.length()-1])
		{
			if (palindrome(x.substr(1, x.length()-2)))
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	int b, i;
	string newsqb;
	scanf("%d", &b);

	for (i=1; i<=300; i++)
	{
		newsqb = convertBase(i*i, b);
		if (palindrome(newsqb)) 
			cout << convertBase(i, b) << ' ' << newsqb << endl;
	}

	return 0;
}