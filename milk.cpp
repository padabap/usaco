/*
ID: yyjoyce1
PROG: milk
LANG: C++
*/

#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);

	int i, n, m, p, a, price=0;
	pair <int, int> milk[5001];

	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &p, &a);
		milk[i] = make_pair(p, a);
	}
	sort(milk, milk+m);

	for (i=0; i<m; i++)
	{
		//if I need more milk than the farmer has
		if (n > milk[i].second)
		{
			price += milk[i].first * milk[i].second;
			n -= milk[i].second;
		}
		else
		{
			price += milk[i].first * n;
			break;
		}
	}

	printf("%d\n", price);
	
	return 0;
}