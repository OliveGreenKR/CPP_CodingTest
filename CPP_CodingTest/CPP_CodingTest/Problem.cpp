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

	struct Road {
		Road(int b, int c) : dest(b), cost(c) {
		}
		int dest = -1;
		int cost = -1;
	};

public:
	SparseTable(int n, int x) {
		_logk = (int)log2(n);
		_lenx = x;
		_parent.resize(_logk+1, vector<int>(_lenx+1,0));

		_maxcost.resize(_logk+1, vector<int>(_lenx+1,MINV));
		_mincost.resize(_logk+1, vector<int>(_lenx+1,MAXV));

		_depth.resize(_lenx+1, 0);
		_adj.resize(_lenx+1);
	}

	void addNode(int a, int b, int c) {
		_adj[a].push_back(Road(b, c));
		_adj[b].push_back(Road(a, c));
	}


	void tableInit() {

		initDepth();

		for (int k = 1; k < _logk+1; k++) {
			for (int i = 2; i < _lenx+1; i++) {
				if (_parent[k-1][i]!=0) {
					_mincost[k][i] = ::min(_mincost[k-1][i],_mincost[k-1][_parent[k-1][i]]);
					_maxcost[k][i] = ::max(_maxcost[k-1][i],_maxcost[k-1][_parent[k-1][i]]);
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

	int gohigh(int n, int x, OUT int& max, OUT int& min) {

		if (n <= 0)
			return x;

		for (int k = (int)log2(n); k >= 0; k--) {
			if ((n & (1<< k)) != 0) {
				min = ::min(min, _mincost[k][x]);
				max = ::max(max, _maxcost[k][x]);
				x = _parent[k][x];
			}
		}
		return x;
	}
	
	void solveQuery(int a, int b) {
		int ha = _depth[a];
		int hb = _depth[b];
		int min = MAXV;
		int max = MINV;

		int h = ::abs(ha -  hb);

		(ha > hb) ? a = gohigh(h, a, max, min) : b = gohigh(h, b, max, min); //now, a and b are same height

		if (a!=b) {
			for (int k = _logk; k >= 0; k--) {
				if (_parent[k][a]!= 0  && _parent[k][a] != _parent[k][b]) {
					max = ::max(max, ::max(_maxcost[k][a], _maxcost[k][b]));
					min = ::min(min, ::min(_mincost[k][a], _mincost[k][b]));
					a = _parent[k][a];
					b = _parent[k][b];
				}
			}
			max = ::max(max, ::max(_maxcost[0][a], _maxcost[0][b]));
			min = ::min(min, ::min(_mincost[0][a], _mincost[0][b]));
			a = _parent[0][a];//LCA 
		}

		//cout ans
		cout << min << " " << max << "\n";

		return;
	}

private:

	void initDepth(int parent = 0, int now = 1, int depth = 0, int cost = 0) {

		int& dep = _depth[now];
		int& par = _parent[0][now];
		int& min = _mincost[0][now];
		int& max = _maxcost[0][now];

		par = parent;
		dep = depth;
		max = cost;
		min = cost;
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
	vector<vector<int>> _maxcost;
	vector<vector<int>> _mincost;

	vector<int> _depth;
	vector<vector<Road>> _adj;
};

int main() {
	FASTIO;
	int N, M;

	cin >> N;

	SparseTable st(N, N);

	//input tree
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		st.addNode(a, b, c);
	}
	st.tableInit();

	cin >> M;

	//input query
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		st.solveQuery(a,b);
	}

	return 0;
}
#endif 
//de bug case  : 1 이 들어갈 때, 현재 root=1이라고 한 상태임.
