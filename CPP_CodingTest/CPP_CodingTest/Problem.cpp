#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
struct Pos
{
	int y; int x; int state=0;
};

enum
{
	MAX_IN = 1<<10,  //1000+@,
};
bool map[MAX_IN][MAX_IN] = {};
bool visited[2][MAX_IN][MAX_IN] = {}; //[º®¶Õ][¹æ¹®¿©ºÎ]
int Gdistance[2][MAX_IN][MAX_IN] = {};
int N, M;
queue<Pos>q = {};
Pos dir[4] =
{
	{-1,0,0},
	{0,1,0},
	{1,0,0},
	{0,-1,0}
};

Pos operator+(const Pos& A, const Pos& B)
{
	return { A.y + B.y , A.x + B.x ,A.state + B.state };
}

inline bool IsRight(Pos x)
{
	if (x.y > N || x.y < 1 || x.x > M || x.x < 1 || visited[x.state][x.y][x.x])
		return false;
	return true;
}

void BFS(Pos now)
{
	q.push(now);
	visited[now.state][now.y][now.x] = true;
	Gdistance[now.state][now.y][now.x] = 1;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		M_Loop(i, 0, 4)
		{
			Pos next = now + dir[i];
			if (IsRight(next))
			{
				if (next.state < 1 && map[next.y][next.x]) //º®¶Õ°¡´É
				{
					next.state++;
				}
				else if (map[next.y][next.x])
					continue;

				q.push(next);
				visited[next.state][next.y][next.x] = true;
				int& dist = Gdistance[next.state][next.y][next.x];
				/*dist > 0 ?
					dist = ::min(Gdistance[next.state][next.y][next.x], Gdistance[now.state][now.y][now.x] + 1) :*/ 
				dist = Gdistance[now.state][now.y][now.x] + 1;
			}

		}
	}
}

int main()
{
	FASTIO;

	cin >> N >> M;
	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, M + 1)
		{
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	Pos st = { 1,1,0 };
	BFS(st);
	
	int dist1 = Gdistance[1][N][M];
	int dist2 = Gdistance[0][N][M];
	if (dist1 && dist2)
		cout << ::min(dist1, dist2) << "\n";
	else if(!dist1 && !dist2)
		cout << -1 << "\n";
	else
		cout << ::max(dist1, dist2) << "\n";
	return 0;
}

#endif 

