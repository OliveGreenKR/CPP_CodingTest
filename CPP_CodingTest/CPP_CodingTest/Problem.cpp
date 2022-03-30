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

int dp[MAX_IN][MAX_IN] = {};  //dp[a][b] == a+1 ~b 까지의 비용 최소값
int sum[MAX_IN] = {}; //sum[a] = 1~a까지의 파일의 크기의 합계
int num[MAX_IN][MAX_IN] = {}; //kruth's optimization
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
        M_Loop(j, 0, K)
        {
            num[j][j+1] = j+1; //데이터하나에 대한k값은 k
        }

        M_Loop(d, 2, K+1) //d=2일 때 부터 시작 (i+1~j까지이므로)
        {
            M_Loop(i, 0, K-d+1)
            {
                int j = i + d;
                dp[i][j] = INT32_MAX;
                M_Loop(k, num[i][j-1], num[i+1][j]+1) //kruth's optimization
                {
                   int tmp = dp[i][k] + dp[k][j] + sum[j] - sum[i];
                   if(tmp < dp[i][j])
                   {
                       dp[i][j] = tmp; 
                       num[i][j] = k;
                   }
                }
            }
        }
        cout << dp[0][K] << "\n";
	}
	return 0;
}
#endif 

