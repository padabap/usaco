/*
ID: yyjoyce1
PROG: dualpal
LANG: C++
*/

#include<cstdio>
#include<string>
using namespace std;

//Convert x from base 10 to base b.
string convertBase(int x, int b)
{
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

//Return true iff x is a palindrome.
bool palindrome(string x)
{
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
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int n, s, num;

	scanf("%d%d", &n, &s);

	while (n>0)
	{
		s++;
		num = 0;
		for (int i=2; i<=10; i++)
		{
			if (palindrome(convertBase(s, i)))
				num++;
			if (num >= 2)
				break;
		}
		if (num >= 2)
		{
			printf("%d\n", s);
			n--;
		}
	}

	return 0;
}