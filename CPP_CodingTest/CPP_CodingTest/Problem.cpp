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
int N, M;
enum :int64
{
	MAX_N = 500+1,
	MAX_M = 6000+1,
	INF = 20000000000000000 //
};
int64 edges[MAX_M][3];
int64 Dist[MAX_N];

void Ford(int now)
{
	M_Loop(j, 1, N + 1)
		Dist[j] = INF;

	Dist[now] = 0;

	M_Loop(i, 0, N)
	{
		M_Loop(j, 0, M)
		{
			int64 now = edges[j][0];int64 next = edges[j][1];int64 cost = edges[j][2];
			if (Dist[now] != INF && Dist[next] > Dist[now] + cost)
			{
				if (i == N-1)
				{
					cout << -1 << "\n";
					return;
				}
				Dist[next] = Dist[now] + cost;
			}
		}
	}

	M_Loop(i, 2, N + 1)
	{
		if (Dist[i] != INF)
			cout << Dist[i] << "\n";
		else
			cout << -1 << "\n";
	}
}

int main()
{
	cin >> N >> M;

	M_Loop(i, 0, M)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edges[i][0] = A;
		edges[i][1] = B;
		edges[i][2] = C;
	}
	Ford(1);
}

#endif 

