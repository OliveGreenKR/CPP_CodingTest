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
#define MAXV (1'000'001)
#define MINV (0)
using namespace std;
using int64 = long long;


class SparseTable {

	struct Edge {
		Edge(int b, int c) : dest(b), cost(c) {
		}
		int dest = 0;
		int cost = 0;
	};

public:
	SparseTable(int n, int x) {
		_logk = ::ceil((int)log2(n));
		_lenx = x;
		_parent.resize(_logk+1, vector<int>(_lenx+1,0));

		_cost.resize(_logk+1, vector<int>(_lenx+1,MINV));

		_depth.resize(_lenx+1, 0);
		_adj.resize(_lenx+1);
	}

	void addNode(int a, int b, int c) {
		_adj[a].push_back(Edge(b, c));
		_adj[b].push_back(Edge(a, c));
	}


	void tableInit() {

		for (int i = 0; i < _lenx-1; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			addNode(a, b, c);
		}

		initDepth();

		for (int k = 1; k < _logk+1; k++) {
			for (int i = 2; i < _lenx+1; i++) {
				if (_parent[k-1][i]!=0) {
					_cost[k][i] = _cost[k-1][i] + _cost[k-1][_parent[k-1][i]];
					_parent[k][i] = _parent[k-1][_parent[k-1][i]];

				}
					
			}
		}

		return;
	}
	//노드 x에서 n만큼 위로
	int gohigh(int n, int x) {

		if (n <= 0)
			return x;

		for (int k = log2(n); k >= 0; k--) {
			if ((n & (1<< k)) != 0)
				x = _parent[k][x];
		}
		return x;
	}

	int gohigh(int n, int x, OUT int& cost, OUT vector<int>& path ) {

		if (n <= 0)
			return x;

		for (int k = (int)log2(n); k >= 0; k--) {
			if ((n & (1<< k)) != 0) {
				cost += _cost[k][x];
				x = _parent[k][x];
				path.push_back(x);
			}
		}
		return x;
	}
	
	pair<int,vector<int>> solveQeury(int a, int b) {
		int ha = _depth[a];
		int hb = _depth[b];
		int cost = MINV;
		vector<int> apath;
		vector<int> bpath;

		apath.push_back(a);
		bpath.push_back(b);

		int h = ::abs(ha -  hb);

		(ha > hb) ? a = gohigh(h, a, cost, apath) : b = gohigh(h, b, cost, bpath); //now, a and b are same height

		if (a!=b) {
			for (int k = _logk; k >= 0; k--) {
				if (_parent[k][a]!= 0  && _parent[k][a] != _parent[k][b]) {
					cost += _cost[k][a] + _cost[k][b];
					a = _parent[k][a];
					b = _parent[k][b];
					apath.push_back(a);
					bpath.push_back(b);
				}
			}
			cost += _cost[0][a] + _cost[0][b];
			a = _parent[0][a];//LCA 
			apath.push_back(a);
		}
		for (int i = (bpath.size()-1); i >=0; i--) {
			apath.push_back(bpath[i]);
		}
		return ::make_pair(cost,apath);
	}

	int Query() {
		int ret = -1;

		int q, a, b, k;

		cin >> q;

		switch(q) {
		case 1:
			cin >> a >> b;
			ret = solveQeury(a, b).first;
			break;
		case 2:
			cin >> a >> b >> k;
			ret = solveQeury(a, b).second[k-1];
			break;
		default:
			break;
		}

		return ret;
	}

private:

	void initDepth(int parent = 0, int now = 1, int depth = 0, int cost = 0) {

		int& dep = _depth[now];
		int& par = _parent[0][now];
		int& mcost = _cost[0][now];

		par = parent;
		dep = depth;
		mcost = cost;
		for (auto road : _adj[now]) {
			int next = road.dest;
			if(parent != next)
				initDepth(now, next, depth+1, road.cost);
		}
		return;
	}

private:
	int _logk;
	int _lenx;
	vector<vector<int>> _parent;
	vector<vector<int>> _cost;

	vector<int> _depth;
	vector<vector<Edge>> _adj;
};

int main() {
	FASTIO;
	int N, M;

	cin >> N;

	SparseTable st(N, N);

	st.tableInit();

	cin >> M;

	//input query
	for (int i = 0; i < M; i++) {
		cout << st.Query() << "\n";
	}

	return 0;
}
#endif 
//de bug case  : 1 이 들어갈 때, 현재 root=1이라고 한 상태임.
