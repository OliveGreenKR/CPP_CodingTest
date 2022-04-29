#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using int64 = long long;
enum : int64
{
	MAX_IN = 800 + 1,
	MAX_E = 20'000 + 1,
	INF = INT32_MAX
};
int64 map[MAX_IN][MAX_IN]; //i~j까지 최단거리
int N, E, V1, V2;

int main()
{
	FASTIO;
	cin >> N >> E;

	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, N + 1)
		{
			if (i != j) map[i][j] = INF;
		}
	}
	M_Loop(i, 0, E)
	{
		int u, v, w; cin >> u >> v;
		cin >> map[u][v]; map[v][u] = map[u][v];
	}

	M_Loop(k, 1, N + 1)  //중간 경유점에 대한 모든 노드들의 경우의수를 구한다.
	{
		M_Loop(i, 1, N + 1)
		{
			M_Loop(j, 1, N + 1)
			{
				int64& now = map[i][j];
				int64 newone = map[i][k] + map[k][j];
				now = now > newone ? newone : now;
			}
		}
	}

	cin >> V1 >> V2;
	if (map[1][V1] >= INF || map[V1][V2] >= INF || map[V2][N] >= INF)
	{
		int64 ans1 = map[1][V1] + map[V1][V2] + map[V2][N];
		int64 ans2 = map[1][V2] + map[V2][V1] + map[V1][N];
		ans1 = ans1 > ans2 ? ans2 : ans1;
		cout << ans1 << "\n";
	}
	else
		cout << -1 << "\n";

	return 0;
}

#endif 




