#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);(i)++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);(i)>(M);(i)--)
using int64 = long long;
enum
{
    MAX_IN = 30+1,
};
int64 N, C, W[MAX_IN], ans;
vector<int64> group1;
vector<int64> group2;

void dfs(int left, int right, vector<int64>& save, int64 sum) //부분합 조합구하기
{
	if (left > right)
	{
		save.push_back(sum);
		return;
	}
	else
	{
		dfs(left + 1, right, save, sum);//포함x
		dfs(left + 1, right, save, sum + W[left]);//포함
	}
}

int main()
{
	FASTIO;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
	}
	// 반으로 나눠서 경우의수 저장  
	dfs(0, N / 2, group1, 0);
	dfs(N / 2 + 1, N - 1, group2, 0);
	sort(group2.begin(), group2.end());

	M_Loop(i,0,group1.size())
	{
		ans += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();
	}
	cout << ans << endl;
}
#endif 


