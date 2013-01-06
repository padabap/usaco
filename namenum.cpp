/*
ID: yyjoyce1
PROG: namenum
LANG: C++
*/

#include<cstdio>
#include<cstring>
using namespace std;

char check(char x)
{
	if (strchr("ABC", x))
		return '2';
	if (strchr("DEF", x))
		return '3';
	if (strchr("GHI", x))
		return '4';
	if (strchr("JKL", x))
		return '5';
	if (strchr("MNO", x))
		return '6';
	if (strchr("PRS", x))
		return '7';
	if (strchr("TUV", x))
		return '8';
	if (strchr("WXY", x))
		return '9';
}

int main()
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	int i, j; 
	bool match=false;
	char name[20], num[13];
	scanf("%s", &num);

	freopen("dict.txt", "r", stdin);
	for (i=0; i<5000; i++)
	{
		scanf("%s", &name);
		for (j=0; j<strlen(name); j++)
		{	
			if (strlen(name) != strlen(num))
				break;
			if (check(name[j]) != num[j])
				break;
		}
		if (j == strlen(name))
		{
			printf("%s\n", name);
			match = true;
		}
	}

	if (match == false)
		printf("NONE\n");

	return 0;
}