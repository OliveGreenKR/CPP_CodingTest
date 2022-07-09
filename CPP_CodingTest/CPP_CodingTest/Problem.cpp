#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
using int64 = long long;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

enum
{
    MAX_IN = 10'000+1,
};
int N;

vector<vector<int>>adj(MAX_IN);
vector<vector<int>>dp(MAX_IN,vector<int>(2)); //[node][state]
vector<bool> visited(MAX_IN, false);
vector<int> weight(MAX_IN);

//1끼리 독립집합만들기, 1끼리 인접못함
void Dfs(int root) {

    dp[root][0] = 0;
    dp[root][1] = weight[root];

    visited[root] = true;

    for (int next : adj[root])
    {
        if (visited[next]) continue;

        Dfs(next);

        dp[root][0] += ::max(dp[next][1], dp[next][0]);
        dp[root][1] += dp[next][0];
    }
}
vector<int> path;
void Track(int state,int now) {
   
    visited[now] = true;

    //자손중 큰 상태를 선택해야함 + 상태확인
	for (int next : adj[now])
	{
        if (visited[next]) continue;

        if (state || dp[next][1] < dp[next][0])
        {
            Track(0, next);
        }
        else if (dp[next][1] > dp[next][0])
        {
            path.push_back(next);
            Track(1, next);
        }
	}
}
void getAns(const int root) {
    visited = vector<bool>(MAX_IN, false);
    adj[0].push_back(root);

    Dfs(0);
    cout << dp[0][0] << "\n";

    visited = vector<bool>(MAX_IN, false);
    Track(0, 0);

    ::sort(path.begin(), path.end());
    for (int n : path)
        cout << n << " ";
}
int main() {
	FASTIO;
    cin >> N;
    path.reserve(N);

    for (int i = 1; i <= N; i++)
        cin >> weight[i];

    for (int i = 0; i < N - 1; i++) //tree
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const int root = 1; //root:1
    getAns(root);

	return 0;
}
#endif 
                      
