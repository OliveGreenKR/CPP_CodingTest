#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using  Node = pair<int, int>;
enum
{
	MAX_IN = 20'000 + 1,
	INF = -1
};
int V, E, K;
int map[MAX_IN][MAX_IN];
int Gdist[MAX_IN]; //K부터 i까지 최단거리

void Dijikstra(int st)
{
	priority_queue<Node, vector<Node>, greater<Node>> q;
	q.push({ 0,st });
	Gdist[st] = 0;
	while (!q.empty())
	{
		Node now = q.top();
		q.pop();
		M_Loop(next, 1, V + 1)
		{
			if (map[now.second][next])
			{
				now.first == Gdist[now.second];
				int& Gdst = Gdist[next];
				int newdst = now.first + map[now.second][next];
				if (newdst < Gdst || Gdst == INF)
				{
					Gdst = newdst;
					q.push({ Gdist[next],next });
				}
			}
		}
	}

}
int main()
{
	FASTIO;
	cin >> V >> E >> K;
	::memset(Gdist, INF, sizeof(Gdist));

	M_Loop(i, 0, E)
	{
		int u, v, w;
		cin >> u >> v >> w;
		int& weight = map[u][v];
		weight = weight ? ::min(weight, w) : w;
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




