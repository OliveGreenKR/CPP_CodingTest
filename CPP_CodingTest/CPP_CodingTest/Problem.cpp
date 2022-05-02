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
int Dist[MAX_IN];
pair<int,bool> Dest[100];
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
	Node now = { 0,st,0 };
	q.push(now);
	Dist[now.idx] = 0;
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
				if (Dist[next.idx]==-1 || Dist[next.idx] >= newdist)
				{
					if ((now.idx == g && next.idx == h) || (now.idx == h && next.idx == g)) next.ck = true;
					Dist[next.idx] = newdist;
					next.dist = newdist;
					M_Loop(j,0,t)
						if (next.idx == Dest[j].first && next.ck) Dest[j].second = true; //목적지 체크
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
		M_Loop(i, 0, t) Dest[i] = { 0,0 };
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
			cin >> Dest[i].first;
		}

		BFS(s);

		::sort(Dest,Dest+t);
		M_Loop(i, 0, t)
		{
			auto ret = Dest[i];
			if (ret.first)
			{
				if (ret.second) cout << ret.first << " ";
			}
			else
				break;
		}
		cout << "\n";
	}
	return 0;
}
#endif 




