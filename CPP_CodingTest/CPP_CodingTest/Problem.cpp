#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;
using int64 = long long;


#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define POW2(x) (std::pow((x),2))
#define INF (1'000'000'000)

namespace bitset {
	int add(int mask, int x) {
		mask |= (1 << x);
		return mask;
	}
	int remove(int mask, int x) {
		mask &= (~(1 << x));
		return mask;
	}
	bool check(const int& mask, int x) {
		return mask & (1 << x) ? 1 : 0;
	}

	int countBit(int mask) {
		int cnt = 0;
		while (mask) {
			cnt += (mask & 1);
			mask >>= 1;
		}
		return cnt;
	}

	int getAll(int x) {
		return (1<<(x))-1;
	}
}
enum {
	R = 0,
	G,
	B,
	None
};

int N;
int allmask;
vector<vector<int>> cost;	//[R][G][B] 도색 비용
vector<int> color;			// node's color
vector<vector<int>> dp;		//dp[mask][color]  mask상태+이전 색 일 때 최소 비용

pair<int, int> getNextColor(int color) {
	if (color == R)
		return make_pair(G, B);
	if (color == G)
		return make_pair(R, B);
	if (color == B)
		return make_pair(R, G);
}

int dfs(int start, int now, int precolor, int mask) {

	if (mask == allmask) {
		if (precolor!= color[start])
			return 0;
		return INF;
	}

	int& ret = dp[mask][precolor];

	if (ret != -1)
		return ret;

	ret = INF;
	int& nowcolor = color[now];
	
	for (int next = 0; next< N; next++) {
		if (bitset::check(mask, next)) //이미 방문
			continue;
		//방문
		int nextmask = bitset::add(mask, now);
		for (int i = 0; i< 3; i++) { 
			if (i == precolor)
				continue;
			nowcolor = i;
			ret = ::min(ret, dfs(start, next, nowcolor, nextmask)+cost[now][nowcolor]);
		}
	}
	return ret;
}

int main() {
	FASTIO;

	cin >> N;

	allmask = bitset::getAll(N);

	cost.resize(N,vector<int>(3,0));
	color.resize(N,None);
	dp.resize(1<<N, vector<int>(4, -1));

	for (auto& c : cost) {
		cin >> c[R] >> c[G] >> c[B];
	}
	
	cout << dfs(0, 0, None, 0);

	return 0;
}
#endif 
