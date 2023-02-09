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

		_cost.resize(_lenx+1, 0);
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
			for (int i = 1; i < _lenx+1; i++) {
				_parent[k][i] = _parent[k-1][_parent[k-1][i]];
			}
		}

		return;
	}
	int gohigh(int n, int x) {

		for (int k = 0; n; k++) {
			if (n & 1)
				x = _parent[k][x];
			n >>= 1;
		}
		return x;
	}

	int getLCA(int a, int b) {
		int ha = _depth[a];
		int hb = _depth[b];
		int h = ::abs(ha -  hb);

		(ha > hb) ? a = gohigh(h, a) : b = gohigh(h, b); //now, a and b are same height

		if (a!=b) {
			for (int k = _logk; k >= 0; k--) {
				if (_parent[k][a] != _parent[k][b]) {
					a = _parent[k][a];
					b = _parent[k][b];
				}
			}
			a = _parent[0][a];
		}

		return a;
	}

	int getKth(int a, int b, int k) {
		int lca = getLCA(a, b);
		int delta = _depth[a] - _depth[lca];
		k--;
		if (delta >= k) {
			k = gohigh(k, a);
		}
		else {
			k = _depth[b] - _depth[lca] - k + delta;
			k = gohigh(k, b);
		}
		return k;
	}

	int getCost(int a, int b) {
		int lca = getLCA(a, b);
		return _cost[a]+_cost[b] -2*_cost[lca];
	}

	int Query() {
		int ret = -1;

		int q, a, b, k;

		cin >> q;

		switch(q) {
		case 1:
			cin >> a >> b;
			ret = getCost(a, b);
			break;
		case 2:
			cin >> a >> b >> k;
			ret = getKth(a, b, k);
			break;
		default:
			break;
		}
		return ret;
	}

private:

	void initDepth(int parent = 0, int now = 1, int depth = 0, int64 cost = 0) {

		int& dep = _depth[now];
		int& par = _parent[0][now];
		int64& mcost = _cost[now];

		par = parent;
		dep = depth;
		mcost = cost;
		for (auto edge : _adj[now]) {
			int next = edge.dest;
			if(parent != next)
				initDepth(now, next, depth+1, edge.cost+cost);
		}
		return;
	}

private:
	int _logk;
	int _lenx;
	vector<vector<int>> _parent;
	vector<int64> _cost;

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

#if 0
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
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

vector<p> g[101010];
ll dp[101010][22];
ll dist[101010];
ll dep[101010];
ll n;
bool chk[101010];

void dfs(ll now, ll d, ll c) {
	chk[now] = 1;
	dep[now] = d;
	dist[now] = c;
	for (auto i : g[now]) {
		ll nxt = i.first;
		if (chk[nxt]) continue;
		ll nxtCost = i.second + c;
		dp[nxt][0] = now;
		dfs(nxt, d+1, nxtCost);
	}
}

void make() {
	for (int j = 1; j<22; j++) {
		for (int i = 1; i<=n; i++) {
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
}

ll getLca(ll u, ll v) {
	if (dep[u] > dep[v]) swap(u, v);
	ll diff = dep[v] - dep[u];
	for (int i = 0; diff; i++) {
		if (diff & 1) v = dp[v][i];
		diff >>= 1;
	}
	if (u == v) return u;
	for (int i = 21; i>=0; i--) {
		if (dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}

ll getDist(ll u, ll v) {
	ll lca = getLca(u, v);
	return dist[u] + dist[v] - 2*dist[lca];
}

ll getkth(ll u, ll v, ll k) {
	ll lca = getLca(u, v);
	ll diff = dep[u] - dep[lca];
	k--;
	if (diff >= k) {
		for (int i = 0; k; i++) {
			if (k & 1) u = dp[u][i];
			k >>= 1;
		}
		return u;
	}

	k = dep[v] - dep[lca] + diff - k;
	for (int i = 0; k; i++) {
		if (k & 1) v = dp[v][i];
		k >>= 1;
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i<n; i++) {
		ll s, e, x; cin >> s >> e >> x;
		g[s].push_back({e, x});
		g[e].push_back({s, x});
	}
	dfs(1, 1, 0); make();

	int m; cin >> m;
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			ll a, b; cin >> a >> b;
			cout << getDist(a, b) << "\n";
		}
		else {
			ll a, b, c; cin >> a >> b >> c;
			cout << getkth(a, b, c) << "\n";

		}
	}
}
#endif