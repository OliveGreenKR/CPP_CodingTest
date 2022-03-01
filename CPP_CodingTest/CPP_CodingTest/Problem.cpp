#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 6 +1
};
int N, M;

int Cost[MAX_IN][MAX_IN];
int Cache[MAX_IN][MAX_IN][4]; // [y][x][dir]]
int Ans = INT32_MAX;


int Path(int y, int x, int dir=0)
{
	if (y > N)
		return 0;

	if (x<=0 || x>M)
		return INT32_MAX;
	
	int& now = Cache[y][x][dir];

	if (now != 0)
		return now;

	if (dir == 1) now = ::min(Path(y + 1,x,2),			Path(y + 1, x + 1, 3))			+ Cost[y][x];
	else if (dir == 2) now = ::min(Path(y + 1, x + 1, 3),	Path(y + 1, x - 1, 1))		+ Cost[y][x];
	else if (dir == 3) now = ::min(Path(y + 1, x, 2), Path(y + 1, x - 1, 1))			+ Cost[y][x];
	else now = ::min({Path(y + 1,x,2), Path(y + 1, x + 1, 3), Path(y + 1, x - 1, 1) })	+ Cost[y][x];

	return now;
}

int main()
{

	cin >> N >> M;

	M_Loop(y, 1, N+1)
	{
		M_Loop(x, 1, M + 1)
		{
			cin >> Cost[y][x];
		}
	}

	M_Loop(x, 1, M + 1)
	{
		Ans = ::min(Path(1, x, 0),Ans);
	}

	cout << Ans << "\n";
}

#endif 