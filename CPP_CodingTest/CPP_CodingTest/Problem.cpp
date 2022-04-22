#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
struct Pos
{
	int y; int x; int dist = 0;
};

enum
{
	MAX_IN = 400,
	DIR = 8
};
int I;
bool map[MAX_IN][MAX_IN];

Pos dir[DIR] =
{
	{-2,1,1},
	{-1,2,1},
	{2,1,1},
	{1,2,1},
	{-2,-1,1},
	{-1,-2,1},
	{2,-1,1},
	{1,-2,1},
};
Pos operator+(const Pos& A, const Pos& B)
{
	return { A.y + B.y , A.x + B.x, A.dist + B.dist};
}
bool operator==(const Pos& A, const Pos& B)
{
	return A.y == B.y && A.x == B.x;
}
inline bool IsRight(Pos x)
{
	if (x.x<0||x.y<0||x.x>=I||x.y>=I||map[x.y][x.x])
		return false;
	return true;
}

int BFS(Pos now, Pos dest)
{
	if (now == dest)
		return 0;

	int result = -1;
	queue<Pos>q;
	q.push(now);
	map[now.y][now.x] = true;

	while (!q.empty())
	{
		now = q.front();
		q.pop();
		M_Loop(i, 0, DIR)
		{
			Pos next = now + dir[i];
			if (IsRight(next))
			{
				q.push(next);
				map[next.y][next.x] = true;
				if (next == dest)
					result = result > 0 ? ::min(result, next.dist) : next.dist;
			}
		}
		
	}
	return result;
}

int main()
{
	FASTIO;
	int T;
	cin >> T;
	M_Loop(i, 0, T)
	{
		::memset(map, 0, sizeof(map));
		int x1, y1, x2, y2; //2:dest
		cin >> I >> y1 >> x1 >> y2 >> x2;
		cout << BFS(Pos{ y1,x1 }, Pos{ y2,x2 }) << "\n";
	}

	return 0;
}

#endif 









//갔던 길 다시 갈수 잇어야함. --> 그럼 중단은 뭘로?
// 
//그와중에 한번갔던 dest는 다시 안가도록?

//w경로선택에 전에 갔던 방향을 가나? 말도안됨 디버깅

/*
enum
{
	MAX_IN = 50+2,  //50+@,
	MAX_K = 3+1,
	MAX_DIR = 4+1,
};
int map[MAX_IN][MAX_IN] = {};
int visited[MAX_K][MAX_IN][MAX_IN] = {};
//int Gdistance[MAX_K][MAX_IN][MAX_IN] = {};
Pos dests[3];
int N, M , Max_dist = INT32_MAX;
Pos dir[4] =
{
	{-1,0,0,0,0},
	{0,1,0,1,0},
	{1,0,0,2,0},
	{0,-1,0,3,0}
};
Pos operator+(const Pos& A, const Pos& B)
{
	return { A.y + B.y , A.x + B.x ,A.state + B.state,B.dir,A.dist+B.dist };
}

inline int IsRight(Pos x)
{
	if (!map[x.y][x.x]||x.state>2||(visited[x.state][x.y][x.x] > 2))//
		return false;
	return true;
}

inline int IsDest(Pos x)
{

	M_Loop(i, 1, 3)
	{
		Pos& dest = dests[i];
		if (dest.y == x.y && dest.x == x.x)
		{
			return i;
		}
	}
	return false;
}
void BFS(Pos now)
{
	queue<Pos>q;
	q.push(now);
	visited[now.state][now.y][now.x]++;
	//Gdistance[now.state][now.y][now.x] = 0;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		M_Loop(i, 0, 4)
		{
			if (i == now.dir)
				continue;
			Pos next = now + dir[i];
			if (IsRight(next))
			{
				int idx = IsDest(next);
				if (idx)
				{
					next.state += idx;
				}
				visited[next.state][next.y][next.x]++;
				//int& dist = Gdistance[next.state][next.y][next.x]; // Gdistance[now.state][now.y][now.x] + 1;
				next.dist++;
				if (next.state == 3)
				{
					Max_dist = ::min(Max_dist, next.dist);
				}
				if(next.dist < Max_dist)
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
	Pos st;
	int idx = 1;
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
				dests[idx++] = { i,j,0,4,0 };
		}
	}

	BFS(st);

	//int dist1 = Gdistance[3][dests[1].y][dests[1].x];
	//int dist2 = Gdistance[3][dests[2].y][dests[2].x];
	//if(dist1&& dist2)
	//	cout << ::min(dist1,dist2)<<"\n";
	//else if (!dist1 && !dist2)
	//	cout << -1 << "\n";
	//else
	//	cout << ::max(dist1, dist2) << "\n";
	if (Max_dist == INT32_MAX)
		Max_dist = -1;
	cout << Max_dist << "\n";
	return 0;
}
*/