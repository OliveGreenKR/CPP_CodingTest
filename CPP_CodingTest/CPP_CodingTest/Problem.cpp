#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define POW(x) (std::pow((x),2))

namespace Bitset {
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
}

vector<vector<int>> cost;
vector<int> dp; // dp[mask]= mask상태의 최소 비용

int N;

enum {
	MAX_M = 10'000
};

int main() {
	FASTIO;
	
	cin >> N; //max=20

	cost.resize(N, vector<int>(N)); //job cost
	dp.resize(1<<N,INT_MAX);
	dp[0]= 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}

	const int maxmask = ::pow(2, N);
	for (int mask = 0; mask < maxmask ; mask++) {
		int x = Bitset::countBit(mask);
		for (int j = 0; j < N; j++) {
			if (!Bitset::check(mask, j)) {
				int nextmask = Bitset::add(mask, j);
				dp[nextmask] = ::min(dp[nextmask], dp[mask] + cost[x][j]);
			}
		}
	}

	cout << dp[dp.size()-1];

	return 0;
}
#endif 
                      