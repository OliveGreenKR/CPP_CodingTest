#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <limits.h>

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define OUT

using namespace std;
using int64 = long long;
using uint = unsigned int;

class Graph {

	using Edge = vector<vector<uint>>;

public:
	Graph(uint n, uint e)  : _N(n) , _E(e) {
		_edges.resize(_N+1);
		_revEdges.resize(_N+1);
		_visited.resize(_N+1, false);
	}

	void init() {
		for (int i = 0; i < _E; i++) {
			uint u, v;
			cin >> u >> v;
			_edges[u].push_back(v);
			_revEdges[v].push_back(u);
		}
	}

	vector<vector<uint>> FindSCC() {

		stack<uint>		stk;

		_visited = vector<bool>(_N+1, false);
		for (uint i = 1; i <= _N; i++) {
			if (!_visited[i])
				dfs(i, _edges, stk);
		}
		_visited = vector<bool>(_N+1, false);

		vector<vector<uint>> results;

		while (!stk.empty()) {
			uint now = stk.top();

			if (!_visited[now]) {
				vector<uint> scc;
				dfscc(now, _revEdges, scc);
				::sort(scc.begin(), scc.end());
				results.push_back(scc);
			}
			stk.pop();
		}

		::sort(results.begin(), results.end());
		return results;
	}

	void dfs(const uint now, Edge& edges, OUT stack<uint>& result) {

		if (_visited[now])
			return;

		_visited[now] = true;

		for (auto& next : edges[now]) {
			if (!_visited[next])
				dfs(next, edges, result);
		}
		result.push(now);
	}

	void dfscc(const uint now, Edge& edges, OUT vector<uint>& result) {

		if (_visited[now])
			return;

		_visited[now] = true;
		result.push_back(now);
		for (auto& next : edges[now]) {
			if (!_visited[next]) {
				dfscc(next, edges, result);
			}
		}
	}


private:
	uint			_N; //# of nodes
	uint			_E;	//# of edges
	Edge			_edges;
	Edge			_revEdges;
	vector<bool>	_visited;
};


int main() {
	FASTIO;

	int V, E;
	cin >> V >> E;

	Graph graph(V, E);
	graph.init();

	auto SCCs = graph.FindSCC();

	cout << SCCs.size() << "\n";

	for (auto scvec : SCCs) {
		for(auto scc :  scvec)
			cout << scc << " ";
		cout << -1 << "\n";
	}

	return 0;
}
#endif 

#if 0
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[10001];
vector<vector<int>> result;
vector<vector<int>> adj;
vector<vector<int>> adjTrans;

stack<int>stk;

void dfs(int root) {
	visited[root] = true;
	for (int i = 0; i < adj[root].size(); i++) {
		if (!visited[adj[root][i]]) {
			dfs(adj[root][i]);
		}
	}
	stk.push(root);
}

void scc(int root) {
	visited[root] = true;
	for (int i = 0; i < adjTrans[root].size(); i++) {
		if (!visited[adjTrans[root][i]]) {
			scc(adjTrans[root][i]);
			result.back().push_back(adjTrans[root][i]);
		}
	}
}

int main() {
	int V, E;

	scanf("%d %d", &V, &E);

	adj.resize(V+1);
	adjTrans.resize(V+1);

	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adjTrans[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i <=V; i++) visited[i] = false;

	while (!stk.empty()) {
		if (!visited[stk.top()]) {
			vector<int> temp(1);
			temp[0] = stk.top();
			result.push_back(temp);
			scc(stk.top());
		}
		stk.pop();
	}

	printf("%lu\n", result.size());

	for (int i = 0; i < result.size(); i++) {
		sort(result[i].begin(), result[i].end());
	}

	sort(result.begin(), result.end());
	for (auto v : result) {
		for (auto i : v) {
			printf("%d ", i);
		}
		printf("-1\n");
	}
}
#endif