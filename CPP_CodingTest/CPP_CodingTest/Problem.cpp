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
int n,m,t,g,h;
enum { MAX_IN = 2000+1,};
int map[MAX_IN][MAX_IN];
pair<int, bool> Dist[MAX_IN];
int Dest[100];
inline bool IsRight(int x, int y)
{
	if(x> n|| x<1 || y > n || y < 1 || !map[x][y])
		return false;
	return true;
}
struct Node
{
	int dist = 0; int idx; bool ck = false;
};
bool operator>(const Node& A, const Node& B) 
{
	return A.dist > B.dist;
}
void BFS(int st)
{
	priority_queue<Node,vector<Node>,greater<Node>> q;
	Node now = { 0,st,false };
	q.push(now);
	Dist[now.idx].first = 0;
	while (!q.empty())
	{
		//탐색 중 목적지체크
		//목적지이면 상태가 g랑 h를 지난 상태면 기록 아니면 폐기.
		now = q.top();
		q.pop();
		M_Loop(i, 1, n + 1)
		{
			if (IsRight(now.idx, i))
			{
				Node next = { 0,i,now.ck }; int newdist = now.dist + map[now.idx][next.idx];
				if ((now.idx == g && next.idx == h) || (now.idx == h && next.idx == g)) next.ck = true;
				if (Dist[next.idx].first==-1 || Dist[next.idx].first >= newdist) //새로운 최단경로
				{
					next.dist = newdist;
					if(next.ck)	Dist[next.idx].second = true;
					else if(Dist[next.idx].first!= newdist) Dist[next.idx].second = false;
					Dist[next.idx].first = newdist;
					q.push(next);
				}
			}
		}
	}
	return;
}
int main()
{
	FASTIO;
	int T;
	cin >> T;
	M_Loop(i, 0, T)
	{
		::memset(Dist, -1, sizeof(Dist)); //-1로 초기화
		::memset(map, 0, sizeof(map)); //-1로 초기화
		cin >> n >> m >> t;
		M_Loop(i, 1, n + 1) Dist[i].second = false;
		int s;
		cin >> s >> g >> h;
		M_Loop(i, 0, m)
		{
			int a, b, d;
			cin >> a >> b >> d;
			map[a][b] = d;
			map[b][a] = d;
		}
		M_Loop(i, 0, t)
		{
			cin >> Dest[i];
		}

		BFS(s);

		::sort(Dest,Dest+t);
		M_Loop(i, 0, t)
		{
			if (Dist[Dest[i]].first != -1 && Dist[Dest[i]].second)
				cout << Dest[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
#endif 




