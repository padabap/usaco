/*
ID: yyjoyce1
PROG: crypt1
LANG: C++
*/

#include<cstdio>
#include<string>
using namespace std;

string dig;

bool check(int x)
{
	while (x >= 0)
	{
		string lastdig = "";
		lastdig += '0' + (x % 10);
		if (dig.find(lastdig) == string::npos)
			return false;
		x = x / 10;
		if (x == x / 10)
			break;
	}
	return true;
}

int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	int n, count=0, d;

	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &d);
		dig += '0' + d;
	}

	for (int i=100; i<=999; i++)
		for (int j=10; j<=99; j++)
			if (check(i) && check(j))
				if (check(i * (j % 10)) && (i* (j % 10) < 1000) )
					if (check(i * (j / 10)) && (i* (j / 10) < 1000) )
						if (check(i * j) && i * j < 10000)
							count++;

	printf("%d\n", count);

	return 0;
}