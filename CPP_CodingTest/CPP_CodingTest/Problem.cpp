#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using int64 = long long;
enum
{
    MAX_IN = 500+1,
};
int64 dp[MAX_IN][MAX_IN] = {}; //dp[i][j] = i~j ÃÖ¼Ò°ö
struct Mat
{
    int64 _r, _c;
};
Mat table[MAX_IN]; //[r][c]

inline int64 GetAns(int l, int r)
{
    if (l == r - 1) return table[l]._r * table[l]._c * table[r]._c;
    if (l == r) return 0;

    int64& cost = dp[l][r];
    if (cost) return dp[l][r];

    cost = INT64_MAX;

    M_Loop(i, l, r) //[l~i] * [i+1~r] 
    {
        cost = ::min(GetAns(l, i) + GetAns(i + 1, r) + table[l]._r * table[i]._c * table[r]._c, cost);
    }
    return cost;
}

int main()
{
	FASTIO;
    int N;
    cin >> N;
    M_Loop(i, 1, N+1)
    {
        int r, c;
        cin >> r >> c;
        table[i] = { r,c };
	}
    GetAns(1, N);
    cout << dp[1][N] << "\n";
	return 0;
}
#endif 


