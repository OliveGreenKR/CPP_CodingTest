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

int64 dp[MAX_IN]; //[val]
pair<int, int> table[MAX_IN]; //[r][c]

inline int64 Mul(int r, int c, int k)
{
    return r*c*k;
}
inline int64 Mulidx(int idx1, int idx2)
{
    return table[idx1].first * table[idx1].second * table[idx2].second;
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
    const int R = table[1].first;
    if (N > 1)
    {
        dp[2] = table[1].first * table[1].second * table[2].second;
    }

    M_Loop(i, 3, N + 1)
    {
        int64 cost1 = dp[i-2] + Mulidx(i-1,i) + Mul(R,table[i-2].second,table[i].second);  // A*BC
        int64 cost2 = dp[i-1] + Mul(R, table[i - 1].second, table[i].second);  // AB*C
        dp[i] = ::min(cost1, cost2);
    }
    cout << dp[N];

	return 0;
}
#endif 

