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
	MAX_IN = 50 + 2,
};
bool visited[MAX_IN][MAX_IN] = {};
bool map[MAX_IN][MAX_IN];
int M,N, CNT = 0;

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

	Pos now = { y,x };
	q.push(now);
	int cnt = 1; //집 개수

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
				cnt++;
				visited[next.first][next.second] = true;
			}
		}
	}
	CNT++; //단지개수++
	return;

}
int main()
{
	FASTIO;
	int T;
	cin >> T;
	M_Loop(i, 0, T)
	{
		CNT = 0;
		int K;
		::memset(map, false, sizeof(map));
		::memset(visited, false, sizeof(visited));
		cin >> M >> N >> K;
		M_Loop(i, 0, K)
		{
			int y, x;
			cin >> x >> y;
			map[y + 1][x + 1] = true;
		}
		
		M_Loop(i, 1, N+1)
		{
			M_Loop(j, 1, M+1)
			{
				if (IsRight(i, j))
					BFS(i, j);
			}
		}
		cout << CNT << "\n";
	}
	
	return 0;
}
#endif 


