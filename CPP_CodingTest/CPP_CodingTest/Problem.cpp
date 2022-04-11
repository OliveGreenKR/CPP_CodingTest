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
	MAX_IN = 25+2,
};
bool visited[MAX_IN][MAX_IN] = {};
bool map[MAX_IN][MAX_IN];
int N, CNT=0;
int ans[1000]; //ans[i] =  i번째 단지의 집 개수

using Pos = pair<int, int>;
Pos dir[4] = {
	{-1,0}, //up
	{0, 1},	//right
	{1, 0},	//down
	{0,-1}	//left
};
Pos operator+( const Pos& left,const Pos& right)
{return { left.first + right.first ,  left.second + right.second };}

inline bool IsRight(int y, int x)
{
	if (y>N|| x>N||y<1||x<1||!map[y][x] || visited[y][x])
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
	ans[CNT] = cnt;
	CNT++; //단지개수++
	return;

}
int main()
{
	FASTIO;
	cin >> N;
	M_Loop(i, 1, N+1)
	{
		M_Loop(j, 1, N+1)
		{
			char c; cin >> c;
			map[i][j] =  c - '0';
		}
	}

	M_Loop(i, 1, N+1)
	{
		M_Loop(j, 1, N+1)
		{
			if (IsRight(i, j))
				BFS(i, j);
		}
	}

	::sort(ans, ans+CNT);
	cout << CNT << "\n";
	M_Loop(i, 0, CNT)
		cout << ans[i] << "\n";
	return 0;
}
#endif 


