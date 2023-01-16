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
vector<vector<int>> dp;		//dp[node][mask] 

//mask : possible bit
int dfs(int now, int mask, int first_color) {

	if (now == N)
		return 0;

	int& ret = dp[now][mask];

	if (ret != -1)
		return ret;

	ret = INF;

	if (now == N-1) {
		mask = bitset::remove(mask, first_color);
		if (mask == 0)
			return INF;
	}

	for (int clr = 0; clr < 3; clr++) { //가능한 RGB 선택
		if (bitset::check(mask, clr)) {
			int nextmask = bitset::remove(allmask, clr);
			ret = ::min(ret, dfs(now+1, nextmask, first_color)+cost[now][clr]);
		}
	}

	return ret;
}

int main() {
	FASTIO;

	cin >> N;

	allmask = bitset::getAll(3);
	cost.resize(N,vector<int>(3,0));
	dp.resize(N, vector<int>(1<<3,-1)); 

	for (auto& c : cost) {
		cin >> c[R] >> c[G] >> c[B];
	}

	int min_val = INF;
	for (int i = 0; i< 3; i++) {
		dp = vector<vector<int>>(N, vector<int>(1<<3, -1));
		min_val = ::min(min_val, dfs(0,1<<i,i));
	}
	cout << min_val;
	return 0;
}
#endif 
