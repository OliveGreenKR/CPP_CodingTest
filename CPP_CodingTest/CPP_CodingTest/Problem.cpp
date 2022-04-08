#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
	MAX_IN = 100 + 1,
	MAX_C = 10'000+ 1
};
int N, M;
int C[MAX_IN]; // 재실행비용
int W[MAX_IN]; // 메모리
int dp[MAX_IN][MAX_C];  // i선택시 j의 비용으로 얻을 수 있는 최대 메모리

int main()
{
	FASTIO;
	cin >> N >> M;

	M_Loop(i, 1, N + 1) cin >> W[i];
	M_Loop(i, 1, N + 1) cin >> C[i];

	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 0, MAX_C)
		{
			if (j - C[i] >= 0) //추가선택가능
				dp[i][j] = ::max(dp[i][j], dp[i - 1][j - C[i]] + W[i]);

			dp[i][j] = ::max(dp[i][j], dp[i - 1][j]);
		}
	}

	M_Loop(j, 0, MAX_C)
	{
		if (dp[N][j] >= M)
		{
			cout << j << "\n";
			break;
		}
	}

	return 0;
}
#endif 


