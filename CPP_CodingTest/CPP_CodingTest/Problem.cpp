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
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

enum
{
    MAX_IN = 10'000+1,
};
int N;

vector<int> weight(MAX_IN,0); 
vector<int> dp(MAX_IN); //i ���� Ž������ �� �ִ� ũ��
vector<vector<int>>adj(MAX_IN);
vector<int>visited(MAX_IN);

void Dfs(int pre, int now, int cost) { //�ֱ� ����, ������ġ, cost
    dp[now] = ::max(dp[now], cost);

    visited[now] = true;

    for (int next : adj[now])
    {
        if (visited[next]) continue;
        if(now != pre)//����
            Dfs(next,next, cost+weight[next]);
        Dfs(pre,next, cost);
    }

    visited[now] = false;
}

void getAns(const int root) {
    adj[0].push_back(root);
    Dfs(-1, 0, 0);


}
int main() {
	FASTIO;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i];
       /* dp[i] = weight[i];*/
    }
    for (int i = 0; i < N - 1; i++) //tree
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //root:1
    const int root = 1;
    getAns(root);

	return 0;
}
#endif 
                                                                                                                                                                                                                                                                                                   