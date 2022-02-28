#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;

enum
{
	MAX_IN = 30 +1
};

int64 DP[MAX_IN] = {};

int main()
{
	FASTIO;
	
	int T;
	cin >> T;
	M_Loop(k, 0, T)
	{
		int M, N;
		cin >> N >> M;

		DP[1] = M;
		M_Loop(j, 2, N + 1)
		{
			DP[j] = (DP[j - 1] * (M - j + 1)) / j;
		}
		cout << DP[N] << "\n";
	}
}

#endif 