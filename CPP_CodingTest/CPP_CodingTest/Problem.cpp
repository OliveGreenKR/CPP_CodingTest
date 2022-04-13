#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
	MAX_IN = 100 + 2,
};
bool visited[MAX_IN][MAX_IN] = {};
bool map[MAX_IN][MAX_IN];
int Gdistance[MAX_IN][MAX_IN] = {};
int M, N;

using Pos = pair<int, int>;
Pos dir[4] = {
	{-1,0}, //up
	{0, 1},	//right
	{1, 0},	//down
	{0,-1}	//left
};
Pos operator+(const Pos& left, const Pos& right)
{
	return { left.first + right.first ,  left.second + right.second };
}

inline bool IsRight(int y, int x)
{
	if (x<1||y<1||x>M||y>N||!map[y][x] || visited[y][x])
		return false;
	return true;
}
void BFS(int y, int x)
{
	if (!IsRight(y, x))
		return;

	visited[y][x] = true;

	queue<Pos> q;
	Pos parent[MAX_IN][MAX_IN] = {};
	Pos now = { y,x };
	q.push(now);
	parent[y][x] = now;
	Gdistance[y][x] = 1;

	while (!q.empty())
	{
		now = q.front();
		if (now == Pos{ N,M }) return;
		q.pop();
	
		M_Loop(i, 0, 4)
		{
			Pos next = now + dir[i];
			if (IsRight(next.first, next.second))
			{
				q.push(next);
				visited[next.first][next.second] = true;
				parent[next.first][next.second] = now;
				Gdistance[next.first][next.second] = Gdistance[now.first][now.second] + 1;
			}
		}
	}
	return;
}
int main()
{
	FASTIO;
	::memset(map, false, sizeof(map));
	::memset(visited, false, sizeof(visited));
	cin >> N >> M;

	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, M + 1)
		{
			char c;cin >> c;
			map[i][j] = c - '0';
		}
	}
	BFS(1, 1);
	cout << Gdistance[N][M] << "\n";

	return 0;
}
#endif 


