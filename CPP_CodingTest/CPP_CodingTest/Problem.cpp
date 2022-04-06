#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using int64 = long long;
enum
{
    MAX_IN = 100+1,
	MAX_K = 10'000+1
};
int N,K;
int arr[MAX_IN]; // 돈의가치
int64 dp[MAX_K];  // j가치의 경우의수

int main()
{
	FASTIO;
    cin >> N >> K;
	M_Loop(i, 1, N+1)
		cin >> arr[i];

	dp[0] = 1;
	M_Loop(i, 1, N + 1) 
		M_Loop(j, arr[i], K + 1)
			dp[j] += dp[j - arr[i]];
	cout << dp[K] << "\n";
	return 0;
}
#endif 




