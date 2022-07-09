#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

enum
{
    MAX_IN = 100000+1,
};
vector<int> dp(MAX_IN,1);
vector<bool> visited(MAX_IN, false);
vector<vector<int>> adj(MAX_IN);
int N, R, Q;

void dfs(int node, int parent) {
    visited[node] = true;
    for (int next : adj[node])
    {
        if (visited[next])
            continue;
        dfs(next, node);
    }
    if (parent != -1)
    {
        dp[parent] += dp[node];
    }
}

int main() {
	FASTIO;
    cin >> N >> R >> Q;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(R, -1);
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
	return 0;
}
#endif 
                                                                                                                                                                                                                                                                                                   