#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define NOTREE cout << "No trees.\n"
#define ONETREE cout << "There is one tree.\n"
#define TTREE(X) cout << "A forest of "<< (X) << " trees.\n"
enum
{
    MAX_IN = 500+1,
};
vector<vector<bool>> adj(MAX_IN, vector<bool>(MAX_IN, false));
vector<int> height(MAX_IN,-1);
int M, N;

inline void InitV()
{
    adj = vector<vector<bool>>(MAX_IN, vector<bool>(MAX_IN, false));
    height = vector<int>(MAX_IN,-1);
}

bool BFS(int now )
{
    int h = 0;
    queue<int> q;
    q.push(now);
    height[now] = h;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        h++;
        for (int next = now+1; next <= N; next++)
        {
            if (adj[now][next])
            {
                if (height[next]!=-1 && height[next] <= h)
                {
                    return false;
                }
                else //사이클
                {
                    q.push(next);
                    height[next] = h;
                }
            }
        }
    }
    return true;
}

int CountTree()
{
    int cnt = 0;

    for (int now = 1; now <= N; now++)
    {
        
        if (height[now]==-1)
        {
            if (BFS(now)) cnt++;
        }
    }
    return cnt;
}

int main()
{
    FASTIO;

    int cscnt = 1;

    while (true)
    {
        cin >> N >> M;
        if (N == 0) break;
        InitV();
        for (int e = 0; e < M; e++)
        {
            int u, v;
            cin >> u >> v;
            adj[u][v] = adj[v][u] = true;
        }
        //출력
        cout << "Case " << cscnt << ": ";
        //개수세기
        int ret = CountTree();

        switch (ret)
        {
        case 0: NOTREE;
            break;
        case 1: ONETREE;
            break;
        default:
            TTREE(ret);
            break;
        }
        cscnt++;
    }

    return 0;
}

#endif 


