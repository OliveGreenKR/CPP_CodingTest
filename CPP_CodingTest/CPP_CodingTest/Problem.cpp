#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using Pos = int;  

enum
{
	MAX_IN = 1<<17  //100'000,
};
bool visited[MAX_IN] = {};
int Gdistance[MAX_IN] = {};
int N,K;

inline bool IsRight(int x)
{
	if (x>100'000||x<0||visited[x])
		return false;
	return true;
}

inline int getNext(int i, Pos x)
{
	switch (i)
	{
	case 0:
		return x + 1;
	case 1:
		return x - 1;
	case 2:
		return x * 2;
	}
}
void BFS(Pos x)
{
	Pos now;
	queue<Pos>q;
	q.push(x);
	while (!q.empty())
	{
		now = q.front();
		visited[now] = true;
		q.pop();
		M_Loop(i, 0, 3)
		{
			Pos next = getNext(i,now);
			if (IsRight(next))
			{
				q.push(next);
				visited[next] = true;
				Gdistance[next] = Gdistance[now] + 1;
				if (next == K)
					return;
			}
		}
	}
	return;
}
int main()
{
	FASTIO;

	cin >> N >> K;
	BFS(N);
	cout << Gdistance[K] << "\n";
	return 0;
}
#endif 


//void BFS(int Y, int X)
//{
//	if (!IsRight(Y, X))
//		return;
//	visited[Y][X] = true;
//	queue<Pos> q;
//	Pos now = { Y,X };
//	q.push(now);
//	Gdistance[Y][X] = 0;
//
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//	
//		M_Loop(i, 0, 4)
//		{
//			Pos next = now + dir[i];
//			if (IsRight(get<Z>(next), get<Y>(next)))
//			{
//				q.push(next);
//				visited[get<Z>(next)][get<Y>(next)] = true;
//				int& dist = Gdistance[get<Z>(next)][get<Y>(next)];
//				if (dist != -1)
//				{
//					dist = ::min(Gdistance[now.first][now.second] + 1, Gdistance[get<Z>(next)][get<Y>(next)]);
//				}
//				else
//					dist = Gdistance[now.first][now.second] + 1;		
//			}
//		}
//	}
//	return;
//}

