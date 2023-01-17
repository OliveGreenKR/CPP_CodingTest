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
#define MAX (1'000'000'003)


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

int N,K; 
int allmask;

vector<vector<int>> dp;		//dp[n][k]  n개에서 k개 고르는 경우의 수 (이항계수)

int Combination(int n, int k) {
	if (n<1 || k<0 || n<k)
		return 0;
	if (k==1)
		return n;
	if (k==0)
		return 1;
	if (n/2 < k)
		return 0;

	int& ret = dp[n][k];

	if (ret != -1)
		return ret;

				//선택+미선택
	return ret = (Combination(n-2, k-1)+Combination(n-1, k))%MAX;
}

int main() {
	FASTIO;

	cin >> N >> K;

	dp.resize(N+1, vector<int>(K+1, -1));

	cout << Combination(N, K);

	return 0;
}
#endif 
