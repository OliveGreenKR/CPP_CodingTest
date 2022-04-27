#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using  Node = pair<int, int>;
enum
{
	MAX_IN = 20'000 + 1,
	MAX_E = 30'000 + 1,
	INF = INT32_MAX
};

int V, E, K;
vector<Node> Edge[MAX_E];
int Gdist[MAX_IN]; //K부터 i까지 최단거리

void Dijikstra(int st)
{
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ 0,st });
	Gdist[st] = 0;
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		for (auto next : Edge[now.second])
		{
			if (next.first > Gdist[next.second]) continue;

			int nextdist = Gdist[now.second] + next.first;
			if (nextdist < Gdist[next.second])
			{
				Gdist[next.second] = nextdist;
				pq.push({nextdist,next.second});
			}
			
		}
	}
}
int main()
{
	FASTIO;
	cin >> V >> E >> K;
	M_Loop(i, 1, V + 1) Gdist[i] = INF;
	M_Loop(i, 0, E)
	{
		int u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({w,v});
	}

	Dijikstra(K);
	M_Loop(i, 1, V + 1)
	{
		int ret = Gdist[i];
		if (ret != INF)
			cout << ret << "\n";
		else
			cout << "INF\n";
	}
	return 0;
}

#endif 




