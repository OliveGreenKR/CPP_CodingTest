#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)

int Board[9][9] = {};
vector<pair<int, int>> GBlanks;

bool Check(int num, const int y, const int x)
{
	M_Loop(i, 0, 9)
	{
		if (Board[y][i] == num || Board[i][x] == num)
			return false;
	}

	int Ry = (y / 3) * 3;
	int Rx = (x / 3) * 3;

	M_Loop(j, Ry, (Ry + 3))
	{
		M_Loop(i, Rx, (Rx + 3))
		{
			if (num == Board[j][i])
				return false;
		}
	}
	return true;
}

void Sdo(int cnt)
{
	if (cnt == GBlanks.size())
	{
		M_Loop(y, 0, 9)
		{
			M_Loop(x, 0, 9)
			{
				cout << Board[y][x] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	auto& c = GBlanks[cnt];
	int y = c.first;
	int x = c.second;

	M_Loop(i, 1, 10)
	{
		if (Check(i, y, x))
		{
			Board[y][x] = i;
			Sdo(cnt + 1);
			Board[y][x] = 0;
		}

	}
}

int main()
{
	FASTIO;

	M_Loop(y, 0, 9)
	{
		M_Loop(x, 0, 9)
		{
			int N;
			cin >> Board[y][x];
			if (!Board[y][x])
				GBlanks.push_back(make_pair(y, x));
		}
	}
	Sdo(0);
}
#endif 