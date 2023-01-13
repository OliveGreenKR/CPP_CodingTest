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

vector<vector<int>> map;
vector<vector<int>> dp; //dp[now][mask] = 현재now 일때, mask 상태의 최소 비용.

int allmask;
int N;

int dfs(int start , int now, int mask) {

	if (mask == allmask) {
		if (map[now][start] != 0)
			return map[now][start];
		return INF;
	}

	int& ret = dp[now][mask];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int next = 0; next < N; next++) {
		if (map[now][next]== 0 || bitset::check(mask,next)) //길이 없거나, 이미 방문
			continue;
		int nextmask = bitset::add(mask, next);
		ret = ::min(ret, dfs(start, next, nextmask)+map[now][next]);
	}
	return ret;
}

int main() {
	FASTIO;

	cin >> N; //max=16

	map.resize(N, vector<int>(N));
	dp.resize(N,vector<int>(1<<(N), -1));

	for (int i = 0; i< N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	allmask = bitset::getAll(N); //모든 도시 방문

	int mask = bitset::add(0, 0);

	cout << dfs(0, 0, mask);

	return 0;
}
#endif 
              
/*
* 답 참고:
https://yabmoons.tistory.com/358 
*/