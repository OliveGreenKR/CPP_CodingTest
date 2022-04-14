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
using Pos = pair<int, int>;
enum
{
	MAX_IN = 1000 + 2,
};
bool visited[MAX_IN][MAX_IN] = {};
int map[MAX_IN][MAX_IN];
int Gdistance[MAX_IN][MAX_IN] = {};
int M, N;
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
	if (x<1||y<1||x>M||y>N|| map[y][x] == -1 || visited[y][x])
		return false;
	return true;
}
void BFS(queue<Pos> q)
{
	Pos now;
	while (!q.empty())
	{
		now = q.front();
		q.pop();

		M_Loop(i, 0, 4)
		{
			Pos next = now + dir[i];
			if (IsRight(next.first, next.second))
			{
				q.push(next);
				visited[next.first][next.second] = true;
				int& dist = Gdistance[next.first][next.second];
				if (dist != -1)
				{
					dist = ::min(Gdistance[now.first][now.second] + 1, Gdistance[next.first][next.second]);
				}
				else
					dist = Gdistance[now.first][now.second] + 1;
			}
		}
	}
	return;
}
int main()
{
	FASTIO;
	::memset(Gdistance, -1, sizeof(Gdistance));
	queue<Pos> q;
	cin >> M >> N;
	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, M + 1)
		{
			int tmt;
			cin >> tmt;
			if (tmt==1)
			{
				map[i][j] = tmt;
				Gdistance[i][j] = 0;
				visited[i][j] = true;
				q.push({i,j});
			}
			else if (tmt == -1)
			{
				visited[i][j] = true;
			}
		}
	}
	BFS(q);
	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, M + 1)
		{
			if (!visited[i][j])
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	int dest=0;
	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, M + 1)
		{
			dest=::max(dest, Gdistance[i][j]);
		}
	}
	cout << dest << "\n";
	return 0;
}
#endif 


//void BFS(int y, int x)
//{
//	if (!IsRight(y, x))
//		return;
//	visited[y][x] = true;
//	queue<Pos> q;
//	Pos now = { y,x };
//	q.push(now);
//	Gdistance[y][x] = 0;
//
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//	
//		M_Loop(i, 0, 4)
//		{
//			Pos next = now + dir[i];
//			if (IsRight(next.first, next.second))
//			{
//				q.push(next);
//				visited[next.first][next.second] = true;
//				int& dist = Gdistance[next.first][next.second];
//				if (dist != -1)
//				{
//					dist = ::min(Gdistance[now.first][now.second] + 1, Gdistance[next.first][next.second]);
//				}
//				else
//					dist = Gdistance[now.first][now.second] + 1;		
//			}
//		}
//	}
//	return;
//}
