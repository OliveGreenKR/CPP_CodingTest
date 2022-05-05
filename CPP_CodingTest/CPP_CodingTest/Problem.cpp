#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using int64 = long long;
int n, m;

enum :int64
{
	MAX_N = 100+1,
	INF = 420000000000
};
int64 dist[MAX_N][MAX_N];

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
		dist[a][b] = ::min(dist[a][b],c);
	}

	Floyd();

	M_Loop(i, 1, n + 1)
	{
		M_Loop(j, 1, n + 1)
		{
			dist[i][j] = dist[i][j] == INF ? 0 : dist[i][j];
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
#endif 

