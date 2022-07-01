#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_IN = 200 + 1,
};
int N, M;
vector<int> parent(MAX_IN);
vector<vector<int>> adj(MAX_IN, vector<int>(MAX_IN));

namespace Set
{
	int Find(int a) {
		if (parent[a] == a)
			return a;
		return parent[a] = Find(parent[a]);
	}
	void Merge(int a, int b) {
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
int main() {
	FASTIO;
	cin >> N >> M;
	for (int u = 1; u <= N; u++)
		parent[u] = u;
	
	for (int u = 1; u <= N; u++)
	{
		for (int v = 1; v <= N; v++)
		{
			cin >> adj[u][v];
			if (adj[u][v])
				Set::Merge(u, v);
		}
	}
	int dest;
	cin >> dest;
	int r = parent[dest];
	for (int i = 1; i < M; i++)
	{
		cin >> dest;
		if (parent[dest] != r)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

#endif 


