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
	int y; int x; int state = 0; int dir=4;
};

enum
{
	MAX_IN = 50+2,  //50+@,
	MAX_K = 2+1,
	MAX_DIR = 4+1,
};
int map[MAX_IN][MAX_IN] = {};
bool visited[MAX_K][MAX_IN][MAX_IN] = {}; 
int Gdistance[MAX_K][MAX_IN][MAX_IN] = {};
Pos dests[2];
int N, M;
Pos st;
Pos dir[4] =
{
	{-1,0,0,0},
	{0,1,0,1},
	{1,0,0,2},
	{0,-1,0,3}
};

Pos operator+(const Pos& A, const Pos& B)
{
	return { A.y + B.y , A.x + B.x ,A.state + B.state,B.dir };
}

inline bool IsRight(Pos x)
{
	if (!map[x.y][x.x]||visited[x.state][x.y][x.x])
		return false;
	return true;
}

inline bool IsDest(Pos x)
{
	
	M_Loop(i, 0, 2)
	{
		Pos& dest = dests[i];
		if (dest.y == x.y && dest.x == x.x)
		{
			return true;
		}
	}
	return false;
}
void BFS(Pos now)
{
	queue<Pos>q;
	q.push(now);
	visited[now.state][now.y][now.x] = true;
	Gdistance[now.state][now.y][now.x] = 0;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		M_Loop(i, 0, 4)
		{
			if (i == now.dir)
				continue;

			Pos next = now + dir[i];
			next.dir = dir[i].dir;
			if (IsRight(next))
			{
				if (IsDest(next)&& next.state <2)
				{
					next.state++;
					/*visited[next.state][next.y][next.x] = true;
					Gdistance[next.state][next.y][next.x] =  Gdistance[now.state][now.y][now.x] + 1;*/
				}
				visited[next.state][next.y][next.x] = true;
				Gdistance[next.state][next.y][next.x] = Gdistance[now.state][now.y][now.x] + 1;
				q.push(next);
			}

		}
	}
}

int main()
{
	FASTIO;
	char c;
	cin >> N >> M;
	
	int idx = 0;
	M_Loop(i, 1, N + 1)
	{
		M_Loop(j, 1, M + 1)
		{
			char c;
			cin >> c;

			map[i][j] = c - '#';
			if (c == 'S')
			{
				st.y = i; st.x = j;
			}
			else if(c == 'C')
				dests[idx++] = { i,j,0,4 };
		}
	}

	BFS(st);

	int ret = ::min(Gdistance[2][dests[0].y][dests[0].x], Gdistance[2][dests[1].y][dests[1].x]);
	if (ret)
		cout << ret << "\n";
	else
		cout << -1 << "\n";

	return 0;
}

#endif 

//갔던 길 다시 갈수 잇어야함. --> 그럼 중단은 뭘로?
// 
//그와중에 한번갔던 dest는 다시 안가도록?