#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using int64 = long long;
int n, m;

enum :int64
{
	MAX_N = 400+1,
	INF = 420'000'000'000
};
int64 dist[MAX_N][MAX_N];
vector<vector<Pair>> edges;
using Pair = pair<int, int>;

struct edge
{
	int from, to, cost;
};
bool operator<(const edge& A, const edge& B)
{
	return A.cost < B.cost;
}
int Dijk()
{
	priority_queue<edge> pq;
	int from, to, cost, next, next_cost;
	for (from = 1; from <= n; from++)
	{
		for (Pair e : edges[from])
		{
			to = e.first;
			cost = e.second;
			dist[from][to] = cost;
			pq.push({ from, to, cost });
		}
	}
	while (!pq.empty())
	{
		from = pq.top().from;
		to = pq.top().to;
		cost = pq.top().cost;
		pq.pop();

		if (dist[from][to] < cost)
			continue;

		if (from == to) return cost;

		for (Pair e : edges[to])
		{
			next = e.first;
			next_cost = e.second + cost;
			if (dist[from][next] > next_cost) {
				dist[from][next] = next_cost;
				pq.push({ from, next, next_cost });
			}
		}
	}
	return -1;
}

void Floyd()
{
	M_Loop(k, 1, n + 1)
	{
		M_Loop(i, 1, n + 1)
		{
			M_Loop(j, 1, n + 1)
			{
				dist[i][j] = ::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void FindCycle()
{
	M_Loop(i, 1, n + 1)
	{
		M_Loop(j, 1, n + 1)
		{
			int64 newdist = dist[i][j] + dist[j][i];
			if (newdist > INF) newdist = INF;
			dist[i][i] = dist[i][i] == 0 ? newdist : ::min(dist[i][i], newdist);
		}
	}
}
int main()
{
	FASTIO;
	cin >> n >> m;
	
	M_Loop(i, 1, n + 1)
		M_Loop(j, 1, n + 1)
		dist[i][j] = i == j ? 0 : INF;
			
	M_Loop(i, 0, m)
	{
		int64 a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	Floyd();
	FindCycle();

	int64 ans = INF;
	M_Loop(i, 1, n + 1)
	{
		ans = ::min(ans, dist[i][i]);
	}
	if (ans < INF)
		cout << ans << "\n";
	else
		cout << "-1\n";
	
	return 0;
}
#endif 

