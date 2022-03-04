#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 1000+1,
	MOD = 10'007
};
int DP[MAX_IN][MAX_IN];

int Combi(const int n, const int k)
{
	if (k < 0 || n < 1 || n <k)
		return 0;
	int& ret = DP[n][k];
	if (ret != 0)
		return ret;
	return ret = (Combi(n - 1, k) + Combi(n - 1, k - 1))%MOD;
}
int main()
{
	FASTIO;
	int N, K;
	cin >> N >> K;

	M_Loop(i, 1, N+1)
	{
		DP[i][0] = 1;
		DP[i][1] = i;
	}
	cout << Combi(N, K);
}
#endif 
