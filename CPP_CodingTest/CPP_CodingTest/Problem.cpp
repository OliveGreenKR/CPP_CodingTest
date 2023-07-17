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
	SCCGraph(uint n, uint e) : _E(e), _edges(n + 1), _visited(n + 1, false), _indegree(n + 1, 0), _sccID(n + 1, 0) {}

	void init() {

		for (int i = 0; i < _E; i++) {
			uint u, v;
			cin >> u >> v;
			_edges[++u].push_back(++v);
		}
	}

	vector<vector<uint>> findSCC() {

		uint _N = _visited.size() - 1;
		vector<bool> finished(_N + 1, false);
		vector<uint> id(_N + 1, NOT_VISIT);
		stack<uint> stk;

		for (uint u = 1; u <= _N; u++) {
			if (id[u] == NOT_VISIT)
				tarjan(u, id, finished, stk);
		}
		return _sccs;
	}

	void answer() {
		uint scc_cnt = _sccs.size();
		uint answer = 0;
		uint cnt_zero = 0;
		for (uint i = 1; i <= scc_cnt; ++i) {
			if (_indegree[i] == 0) {
				answer = i;
				++cnt_zero;
			}
		}
		if (cnt_zero == 1) {
			
			for (auto& e : _sccs[--answer])
				cout << --e << "\n";
		} else {
			cout << "Confused\n";
		}
	}

private:

	uint tarjan(uint now, vector<uint>& ids, vector<bool>& finished, stack<uint>& stk) {
		uint& id = ++ids[0];
		uint low;
		static uint SCC_id = 0;
		ids[now] = id;
		low = id;
		stk.push(now);

		for (auto next : _edges[now]) {
			uint& nextid = ids[next];
			if (nextid == NOT_VISIT) //not visit
				low = ::min(low, tarjan(next, ids, finished, stk));
			else if (!finished[next]) //visited, but not finished
				low = ::min(low, nextid);
			else {  //visited finished one
				++_indegree[_sccID[next]];
			}
		}

		//now is the first detected one in cycles == scc's root
		if (low == ids[now]) {
			vector<uint> scc;
			++SCC_id;
			while (1) {
				uint top = stk.top();
				stk.pop();
				scc.push_back(top);
				finished[top] = true;
				_sccID[top] = SCC_id;

				if (top == now)
					break;
			}

			if (!stk.empty()) //남아있는 요소가 있다 -> 상위 SCC에서 진입이 있었다.
				++_indegree[_sccID[now]];
			::sort(scc.begin(), scc.end());
			_sccs.push_back(scc);
		}

		return low;
	}


private:
	uint	_E;
	vector<vector<uint>>	_edges;
	vector<vector<uint>>	_sccs;
	vector<bool>			_visited;
	vector<uint>			_indegree;
	vector<uint>			_sccID;
};

int main() {
	FASTIO;

	int T ,V, E;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> V >> E;
		SCCGraph graph(V, E);
		graph.init();
		graph.findSCC();
		graph.answer();
	}

	return 0;
}
#endif 

#if 0

#endif