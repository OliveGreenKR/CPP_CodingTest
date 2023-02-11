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
	enum : uint {
		NOT_VISIT = 0,
	};

public:
	SCCGraph(uint n, uint e) : _N(n), _E(e) {
		_edges.resize(_N+1);
		_visited.resize(_N+1, false);
	}

	void init(){

		for (int i = 0; i < _E; i++) {
			uint u, v;
			cin >> u >> v;
			_edges[u].push_back(v);
		}
	}

	vector<vector<uint>> findSCC() {

		vector<bool> finished(_N+1, false);
		vector<uint> id(_N+1, NOT_VISIT);
		stack<uint> stk;

		for (uint u = 1; u <= _N; u++) {
			if(id[u] == NOT_VISIT)
				dfs(u, id, finished, stk);
		}
		::sort(_sccs.begin(), _sccs.end());
		return _sccs;
	}
private:

	uint dfs(uint now, vector<uint>& ids, vector<bool>& finished, stack<uint>& stk) {
		uint& id = ++ids[0];
		uint parent;

		ids[now] = id;
		parent = id;
		stk.push(now);

		for (auto next : _edges[now]) {
			uint& nextid = ids[next];
			if (nextid == NOT_VISIT) //not visit
				parent = ::min(parent, dfs(next, ids, finished, stk));
			else if (!finished[next]) //visited, but not finished
				parent = ::min(parent, nextid);
		}

		//now is the first detected one in cycles == scc's root
		if (parent == ids[now]) {
			vector<uint> scc;

			while (1) {
				uint top = stk.top();
				stk.pop();
				scc.push_back(top);
				finished[top] = true;

				if (top ==  now)
					break;
			}
			::sort(scc.begin(), scc.end());
			_sccs.push_back(scc);
		}

		return parent;
	}


private:
	uint	_N;
	uint	_E;
	vector<vector<uint>>	_edges;
	vector<vector<uint>>	_sccs;
	vector<bool>			_visited;
};

int main() {
	FASTIO;

	int V, E;
	cin >> V >> E;

	SCCGraph graph(V, E);
	graph.init();

	auto sccs = graph.findSCC();

	cout << sccs.size() << "\n";

	for (auto& scc : sccs) {
		for (auto& sc : scc)
			cout << sc << " ";
		cout << -1 << "\n";
	}

	return 0;
}
#endif 

#if 0

#endif