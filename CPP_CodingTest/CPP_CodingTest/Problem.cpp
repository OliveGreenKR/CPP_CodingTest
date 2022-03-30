#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>

using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

enum
{
    MAX_IN = 500+1
};

int dp[MAX_IN][MAX_IN] = {};  //dp[a][b] == a~b 까지의 비용 최소값
int sum[MAX_IN] = {}; //sum[a] = 0~a까지의 파일의 크기의 합계
int main()
{
	FASTIO;
    int T;
    cin >> T;
    M_Loop(i, 0, T)
    {
        int K;
        cin >> K;
        M_Loop(j, 1, K+1)
        {
            cin >> sum[j];
            sum[j] += sum[j - 1];
        }
        M_Loop(d, 1, K)
        {
            M_Loop(i, 1, K+1-d)
            {
                int j = i + d;
                dp[i][j] = INT32_MAX;
                M_Loop(k, i, j)
                {
                    dp[i][j] = ::min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }
        cout << dp[1][K] << "\n";
	}
	return 0;
}
#endif 
