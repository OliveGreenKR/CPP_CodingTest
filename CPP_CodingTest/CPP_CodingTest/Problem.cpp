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
enum {
	R = 0,
	G,
	B,
	None
};

int N,K; 
int allmask;
vector<vector<int>> cost;	//[R][G][B] 도색 비용
vector<int> color;			// node's color
vector<vector<int>> dp;		//dp[node][mask] 


int dfs(int k, int now) {

	//종료조건 
	/*
	* todo : 
	* now == N-1 ,  return adj ? 1 : 0
	* now ==  N ,  return 0;
	*/

	//초기화

	//탐색
	/*
	* 
	* dp[k][now] =  now에서 부터 k 고를 때 가능한 개수.
	* 
	* dp[k][now] += dfs(k-1, now+1);
	*
	*/

}

int main() {
	FASTIO;

	cin >> N >> K;


	return 0;
}
#endif 
