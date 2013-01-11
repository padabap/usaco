/*
ID: yyjoyce1
PROG: calfflac
LANG: C++
*/

#include<fstream>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string x = "";

struct triple {
	int len, start, chars;
};

triple find_odd(int center)
{
	triple done = {1, center, 1};
	int i = 1, j = 1;
	if (!isalpha(x[center]))
	{
		done.len = 0; done.start = -1; done.chars = 0;
		return done;
	}
	while (1)
	{
		if (center-i < 0 || center+j >= x.length())
			break;
		else
		{
			if (!isalpha(x[center-i]))
				j--;
			else if (!isalpha(x[center+j]))
				i--;
			else if (tolower(x[center-i]) == tolower(x[center+j]))
			{
				done.len += 2;
				done.start = center-i;
				done.chars = i+j+1;
			}
			else
				return done;
			i++; j++;
		}
	}
	return done;
}

triple find_even(int center)
{
	triple done = {0, -1, 0};
	int i = 0, j = 1;
	if (!isalpha(x[center]))
		return done;
	while (1)
	{
		if (center-i < 0 || center+j >= x.length())
			break;
		else
		{
			if (!isalpha(x[center-i]))
				j--;
			else if (!isalpha(x[center+j])) //if it's not a letter
				i--;
			else if (tolower(x[center-i]) == tolower(x[center+j]))
			{
				done.len += 2;
				done.start = center-i;
				done.chars = i+j+1;
			}
			else
				break;
			i++; j++;
		}
	}
	return done;
}

triple m(triple i, triple j)
{
	if (i.len > j.len)
		return i;
	else
		return j;
}

int main()
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");

	int i; string line;
	triple pal, max;
	max.len = 0;

	while (!fin.eof())
	{
		getline(fin, line);
		x += line += "\n";
	}
	
	for (i=0; i<x.length(); i++)
	{
		pal = m(find_odd(i), find_even(i));
		if (pal.len > max.len)
			max = pal;
	}

	fout << max.len << endl;
	fout << x.substr(max.start, max.chars) << endl;
	return 0;
}