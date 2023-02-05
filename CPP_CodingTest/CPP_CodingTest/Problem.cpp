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


class SparseTable {
public:
	SparseTable(int n, int x) {
		_logk = (int)log2(n);
		_lenx = x;
		_parent.resize(_logk+1, vector<int>(_lenx+1));
		_depth.resize(_lenx+1, -1);
		_adj.resize(_lenx+1);
	}

	void addNode(int a, int b) {
		_adj[a].push_back(b);
		_adj[b].push_back(a);
	}


	void tableInit() {

		initDepth();

		for (int k = 1; k < _logk+1; k++) {
			for (int i = 2; i < _lenx+1; i++) {
				if (_parent[k-1][i]!=0)
					_parent[k][i] = _parent[k-1][_parent[k-1][i]];
			}
		}

		return;
	}
	//노드 x에서 n만큼 위로
	int query(int n, int x) {

		if (n <= 0)
			return x;

		for (int k = log2(n); k >= 0; k--) {
			if ((n & (1<< k)) != 0)
				x = _parent[k][x];
		}
		return x;
	}


	int findLCA(int a, int b) {
		int ha = _depth[a];
		int hb = _depth[b];
		int h = ::abs(ha -  hb);

		(ha > hb) ? a = query(h, a) : b = query(h, b); //now, a and b are same height


		if (a!=b) {
			for (int k = _logk; k >= 0; k--) {
				if (_parent[k][a]!= 0  && _parent[k][a] != _parent[k][b]) {
					a = _parent[k][a];
					b = _parent[k][b];
				}
			}
			a=_parent[0][a];
		}

		return a;
	}

private:

	void initDepth(int parent = 0, int now = 1, int depth = 0) {

		int& dep = _depth[now];
		int& par = _parent[0][now];

		if (dep != -1 || now < 1)
			return;

		par = parent;
		dep = depth;
		for (auto next : _adj[now]) {
			if(now != next)
				initDepth(now, next, depth+1);
		}
	}

private:
	int _logk;
	int _lenx;
	vector<vector<int>> _parent;
	vector<int> _depth;
	vector<vector<int>> _adj;
};

int main() {
	FASTIO;
	int N, M;

	cin >> N;

	SparseTable st(N, N);

	//input tree
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		st.addNode(a, b);
	}
	st.tableInit();

	cin >> M;

	//input query
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << st.findLCA(a, b) << "\n";
	}

	return 0;
}
#endif 
