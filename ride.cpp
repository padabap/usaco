/*
ID: yyjoyce1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string comet, group;
	int i, pcomet=1, pgroup=1;

	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	cin >> comet;
	cin >> group;

	for (i=0; i<comet.length(); i++)
		pcomet = pcomet * (comet[i]-64);

	for (i=0; i<group.length(); i++)
		pgroup = pgroup * (group[i]-64);

	if (pcomet%47 == pgroup%47)
		cout << "GO\n";
	else
		cout << "STAY\n";

	return 0;
}