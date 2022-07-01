#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_IN = 200 + 1,
};
int N, M;
vector<int> parent(MAX_IN);
vector<vector<int>> adj(MAX_IN, vector<int>(MAX_IN));
vector<int> plan(1000);

namespace Set
{
	int Find(int a) {
		if (parent[a] == a)
			return a;
		return parent[a] = Find(parent[a]);
	}
	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a > b) parent[a] = b;
		else
			parent[b] = a;
	}
	bool isSame(int a, int b) {
		return Find(a) == Find(b);
	}

};

void GetSet(int st, vector<bool>& visit) {
	queue<int> q;
	q.push(st);
	while (!q.empty())
	{
		st = q.front();
		q.pop();

		for (int next=1;next<=N;next++)
		{
			if (adj[st][next] && !visit[next] && !Set::isSame(st,next))
			{
				Set::Union(st, next);
				q.push(next);
				visit[next] = true;
			}
		}
	}
	visit[st] = true;
}
void MergeSets() {
	vector<bool> visit(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		if (visit[i]) continue;
		GetSet(i, visit);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	for (int u = 1; u <= N; u++)
	{
		parent[u] = u;
		for (int v = 1; v <= N; v++)
		{
			cin >> adj[u][v];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> plan[i];
	}
	//연결 집합 묶기
	MergeSets();
	//여행경로 부모와 비교

	int r = parent[plan[0]];
	for (int i=0;i<M;i++)
	{
		if (parent[plan[i]] != r)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

#endif 


