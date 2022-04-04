#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
    MAX_IN = 2'000+1,
};
int arr[MAX_IN];
int dp[MAX_IN][MAX_IN];  //[i]~[j]까지 팰런드럼 여부
int ans[MAX_IN];

int GetAns(int l, int r)
{
	int& now = dp[l][r];
	if (l >= r)
		now = true;
	if (now != -1)
		return now;

	if (arr[r] != arr[l])
		now = false;
	else
		now = GetAns(l + 1,r - 1);

	return now;
}
int main()
{
	::memset(dp, -1, MAX_IN * MAX_IN * sizeof(int));

    int N;
	FASTIO;
    cin >> N;

	M_Loop(i, 1, N + 1)
		cin >> arr[i];
	int M;
	cin >> M;
	M_Loop(i, 0, M)
	{
		int S, E;
		cin >> S >> E;
		cout << GetAns(S, E) << "\n";
	}
	return 0;
}
#endif 




