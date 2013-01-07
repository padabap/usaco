/*
ID: yyjoyce1
PROG: barn1
LANG: C++
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);

	int i, m, s, c, stall, empty[250], size, j=0, min=501, max=0, total=0;;
	bool cow[501];

	memset(cow, false, sizeof(cow));
	scanf("%d%d%d", &m, &s, &c);
	for (i=0; i<c; i++)
	{
		scanf("%d", &stall);
		cow[stall] = true;
		if (stall < min)
			min = stall;
		if (stall > max)
			max = stall;
	}

	for (i=min; i<max; i++)
	{
		if (cow[i] == false)
		{
			size=1;
			while (cow[i+size] == false)
				size++;
			empty[j] = size;
			j++;
			i = i+size;
		}
	}
	sort(empty, empty+j);

	for (i=0; i<j-m+1; i++)
		total = total + empty[i];

	printf("%d\n", total+c);
	return 0;
}