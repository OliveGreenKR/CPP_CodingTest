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
    MAX_IN = 1'000'000+1,
};
int N;

vector<vector<int>>adj(MAX_IN);
vector<vector<int>>dp(MAX_IN,vector<int>(2)); //[node][state]
vector<bool> visited(MAX_IN, false);

enum
{
    adaptor,
    normal,
};
//normal끼리 독립집합만들기, normal끼리 인접못함
void Dfs(int root) {

    dp[root][adaptor] = 0;
    dp[root][normal] = 1;

    visited[root] = true;

    for (int next : adj[root])
    {
        if (visited[next]) continue;

        Dfs(next);

        dp[root][adaptor] += ::max(dp[next][normal], dp[next][adaptor]);
        dp[root][normal] += dp[next][adaptor];
    }
}
  
void getAns(const int root) {
    adj[0].push_back(root);
    Dfs(0);
    cout << N - dp[0][adaptor];
}
int main() {
	FASTIO;
    cin >> N;

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
                                                                                                                                                                                                                                                                                                   