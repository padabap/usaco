/*
ID: yyjoyce1
PROG: transform
LANG: C++
*/


#include<cstdio>
#include<cstring>
using namespace std;

struct Board
{
	char board[11][11];
};
Board rotate(Board old, int n)
{
	Board t;
	for (int x=0; x<n; x++)
		for (int y=0; y<n; y++)
			t.board[y][n-1-x] = old.board[x][y];
	return t;		
}
Board reflect(Board old, int n)
{
	Board t;
	for (int x=0; x<n; x++)
		for (int y=0; y<n; y++)
			t.board[x][n-1-y] = old.board[x][y];
	return t;
}
bool equal(Board a, Board b, int n)
{
	bool check=true;
	for (int x=0; x<n; x++)
		for (int y=0; y<n; y++)
			if (a.board[x][y] != b.board[x][y])
			{
				check = false;
				break;
			}
	return check;
}
int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	int n, i, j;
	Board before, after;

	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("\n");
		for (j=0; j<n; j++)
			scanf("%c", &before.board[i][j]);
	}
	for (i=0; i<n; i++)
	{
		scanf("\n");
		for (j=0; j<n; j++)
			scanf("%c", &after.board[i][j]);
	}

	Board once = rotate(before, n);
	Board twice = rotate(rotate(before, n), n);
	Board thrice = rotate(rotate(rotate(before, n), n), n);

	if (equal(once, after, n))
		printf("1\n");
	else if (equal(twice, after, n))
		printf("2\n");
	else if (equal(thrice, after, n))
		printf("3\n");
	else if (equal(reflect(before, n), after, n))
		printf("4\n");
	else if (equal(reflect(once, n), after, n) || equal(reflect(twice, n), after, n) || equal(reflect(thrice, n), after, n))
		printf("5\n");
	else if (equal(before, after, n))
		printf("6\n");
	else
		printf("7\n");
	
	return 0;
}