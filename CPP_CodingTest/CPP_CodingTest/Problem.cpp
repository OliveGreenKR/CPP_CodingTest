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
#include <limits.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define POW(x) (std::pow((x),2))

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
		return (1<<(x+1))-1;
	}
}

vector<vector<int>> map;
vector<int> dp; // dp[mask]= mask상태의 최소 비용

int allmask;
int lastmask;
int N;


void dfs(int start , int now, int mask) {
	if (mask == allmask) {
		if (map[now][start] != 0)
			dp[lastmask] = ::min(dp[lastmask], dp[allmask]+map[now][start]);
		return;
	}

	for (int next = 0; next < N; next++) {
		if (map[now][next]== 0 || bitset::check(mask,next)) //길이 없거나, 이미 방문
			continue;
		int nextmask = bitset::add(mask, next);
		int nextdp = dp[nextmask];
		dp[nextmask] = ::min(nextdp, dp[mask]+map[now][next]);
		dfs(start, next, nextmask); //지금 방문
		dp[nextmask] = nextdp; //방문 안함
	}
}

int main() {
	FASTIO;

	cin >> N; //max=16

	map.resize(N, vector<int>(N));
	dp.resize(1<<(N+1), INT_MAX);

	for (int i = 0; i< N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	allmask = bitset::getAll(N-1); //모든 도시 방문
	lastmask = bitset::getAll(N);  //복귀까지 성공

	int mask = bitset::add(0, 0);
	dp[mask] = 0;
	dfs(0, 0,mask);

	cout << dp[lastmask];

	return 0;
}
#endif 
                      