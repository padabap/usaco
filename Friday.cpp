/*
ID: yyjoyce1
PROG: friday
LANG: C++
*/

#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);

	int N, i, j, week[8], m[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, start=2;
	memset(week, 0, sizeof(week));
	scanf("%d", &N);

	for (i=1900; i<=1900+N-1; i++)
	{
		if ((i%100 == 0 && i%400 == 0) || (i%4 == 0 && i%100 != 0))
			m[1] = 29;
		else
			m[1] = 28;
		for (j=0; j<12; j++)
		{
			week[(start + 5) % 7]++;
			start = (start + m[j]%7) % 7;
		}
	}

	for (i=0; i<7; i++)
	{
		printf("%d", week[i]);
		if (i<6)
			printf(" ");
	}

	printf("\n");

	return 0;
}