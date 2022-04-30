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
int N, K;
enum { MAX_IN = 100'000+1,};
int Dist[MAX_IN];
inline bool IsRight(int x)
{
	if(x>=MAX_IN|| x<0||Dist[x]!=-1)
		return false;
	return true;
}
void BFS(int now)
{
	int dir[2] = { -1,+1 };
	queue<int> q;
	Dist[now] = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.front(); q.pop();
		M_Loop(i, 0, 3)
		{
			int next=now;
			if (i < 2) next += dir[i];
			else next *= 2;

			if (IsRight(next))
			{
				if (i < 2)
					Dist[next] = Dist[now] + 1;
				else
					Dist[next] = Dist[now];
				q.push(next);
			}
		}
	}
	return;
}
int main()
{
	FASTIO;
	cin >> N >> K;
	::memset(Dist, -1, sizeof(Dist));
	BFS(N);

	cout << Dist[K] << "\n";

}
#endif 




