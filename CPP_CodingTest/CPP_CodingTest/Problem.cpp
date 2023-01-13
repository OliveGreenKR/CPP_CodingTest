#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <limits.h>
#include <string>

using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define POW2(x) (std::pow((x),2))

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

int N, K;

vector<string> sets;
vector<vector<int>> dp; 

uint64 getFactorial(int x) {
	if (x == 0 || x == 1) 
		return 1;
	return x * getFactorial(x-1);
}



int main() {
	FASTIO;

	cin >> N; //max=15

	sets.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> sets[i];
	}
	cin >> K;

	uint64 numer, denom; //분자, 분모;

	denom = getFactorial(N);
	
	uint64 gcd = ::gcd(numer, denom);


	return 0;
}
#endif 
