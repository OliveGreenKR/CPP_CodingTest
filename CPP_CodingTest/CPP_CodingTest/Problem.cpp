#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using Pos = pair<int,int>;  

enum
{
	MAX_IN = 1<<10,  //1000+@,
};
bool map[MAX_IN][MAX_IN] = {};
bool visited[2][MAX_IN][MAX_IN] = {}; //[벽뚫][방문여부]
int Gdistance[MAX_IN][MAX_IN] = {};
int N, M;
queue<Pos>q = {};
Pos dir[4] =
{
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};

Pos operator+(const Pos& A, const Pos& B)
{
	return { A.first + B.first , A.second + B.second };
}

inline bool IsRight(Pos x)
{
	if (x.first > N || x.first < 1 || x.second > M || x.second < 1)
		return false;
	return true;
}

void BFS(queue<Pos>&q)
{
	Pos dest = { N,M };
	while (!q.empty())
	{
		Pos now = q.front();
		q.pop();
		M_Loop(i, 0, 4)
		{
			Pos next = now + dir[i];
		
			
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
	Pos x = { 1,1 };
	q.push(x);

	BFS(q);
	
	if(!Gdistance[N][M])
		cout << -1 << "\n";
	else
		cout << Gdistance[N][M] << "\n";
	return 0;
}
#endif 

