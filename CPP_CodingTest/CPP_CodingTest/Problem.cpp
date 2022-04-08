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
int C[MAX_IN]; // �������
int W[MAX_IN]; // �޸�
int dp[MAX_IN][MAX_C];  // i���ý� j�� ������� ���� �� �ִ� �ִ� �޸�

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
			if (j - C[i] >= 0) //�߰����ð���
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


