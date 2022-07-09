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

vector<int> weight(MAX_IN,0); 
vector<vector<int>>adj(MAX_IN);
vector<vector<int>>dp(MAX_IN,vector<int>(2)); //[node][state]
vector<bool> visited(MAX_IN, false);

void Dfs(int root) {
    dp[root][0] = 0;
    dp[root][1] = weight[root];

    visited[root] = true;

    for (int next : adj[root])
    {
        if (visited[next]) continue;
        Dfs(next);

        dp[root][0] += ::max(dp[next][0], dp[next][1]);
        dp[root][1] += dp[next][0];
    }
}
  
void getAns(const int root) {
    adj[0].push_back(root);
    Dfs(0);
    cout << ::max(dp[0][0], dp[0][1]);
}
int main() {
	FASTIO;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i];
    }
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
                                                                                                                                                                                                                                                                                                   