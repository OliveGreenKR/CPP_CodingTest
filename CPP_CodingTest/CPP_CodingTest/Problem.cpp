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

class SCCGraph {

	using Edge = vector<vector<uint>>;

public:
	SCCGraph(uint n, uint e) : _N(n), _E(e) {
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

	uint GetTopologies() {

		stack<uint>		stk;

		_visited = vector<bool>(_N+1, false);
		for (uint i = 1; i <= _N; i++) {
			if (!_visited[i])
				dfs(i, _edges, stk);
		}
		_visited = vector<bool>(_N+1, false);

		//vector<vector<uint>> results;
		uint cnt = 0;

		while (!stk.empty()) {
			uint now = stk.top();

			if (!_visited[now]) {
				vector<uint> scc;
				dfscc(now, _edges, scc);
				cnt++;
				//::sort(scc.begin(), scc.end());
				//results.push_back(scc);
			}
			stk.pop();
		}

		//::sort(results.begin(), results.end());
		return cnt;
	}

	void dfs(const uint now, Edge& edges, stack<uint>& result) {

		if (_visited[now])
			return;

		_visited[now] = true;

		for (auto& next : edges[now]) {
			if (!_visited[next])
				dfs(next, edges, result);
		}
		result.push(now);
	}

	void dfscc(const uint now, Edge& edges, vector<uint>& result) {

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

	int T ,V, E;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> V >> E;
		SCCGraph graph(V, E);
		graph.init();
		cout << graph.GetTopologies() << "\n";
	}
	
	return 0;
}
#endif 

#if 0

#endif