#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
	MAX_IN = 1000+1,
};
using graph = vector<vector<bool>>;
graph adjac(MAX_IN,vector<bool>(MAX_IN));//[i]와 연결된 노드들[j]
bool visited[MAX_IN];
int N, M, V;

void BFS(int st)
{
	queue<int> q;
	visited[st] = true;
	q.push(st);
	while (!q.empty())
	{
		st = q.front();
		cout << st << " ";
		q.pop();
		M_Loop(i, 1, N + 1)
		{
			bool next = adjac[st][i];
			if (next && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << "\n";
}

void DFS(int st)
{
	stack<int> s;
	s.push(st);
	while (!s.empty())
	{
		st = s.top();
		s.pop();
		if (!visited[st])
		{
			cout << st << " ";
			visited[st] = true;
		}
		M_Loop_sub(i, N, 0)
		{
			bool next = adjac[st][i];
			if (next && !visited[i])
				s.push(i);
		}
	}
	cout << "\n";
}

int main()
{
	FASTIO;
	cin >> N >> M >> V;
	M_Loop(i, 0, M)
	{
		int st, dt;
		cin >> st >> dt;
		adjac[st][dt]=true;
		adjac[dt][st]=true;
	}
	::memset(visited, 0, sizeof(visited));
	DFS(V);
	::memset(visited, 0, sizeof(visited));
	BFS(V);
	return 0;
}
#endif 


