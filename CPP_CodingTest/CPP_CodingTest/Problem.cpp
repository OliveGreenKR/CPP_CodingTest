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
int allmask;

vector<string>	sets;			//순열 원소
vector<int>		setslen;		//순열 원소 길이
vector<int>		digitmod;			//자릿수에 대한 mod
vector<vector<int64>> dp;			//dp[mask][nowmod]

int64 getFactorial(int x) {
	if (x == 0 || x == 1) 
		return 1;
	return x * getFactorial(x-1);
}

int getModSTR(string& str, int x) { 
	int ret = 0;
	for (auto& s : str) {
		int n = s -'0';
		ret = ((ret*10)+n) % x;
	}
	return ret;
}

//dp[mask][now] 값 return
int64 dfs(int now, int mask) {			
	
	if (mask == allmask) {
		if (now==0)
			return 1;
		return 0;
	}
	int64& ret = dp[mask][now];
	
	if (ret != -1)
		return ret;

	ret = 0;

	for (int next = 0; next < N; next++) {
		if (bitset::check(mask, next))
			continue;
		//todo : nextmod 자릿수 생각
		int nextmod = (now*digitmod[setslen[next]]+(int)sets[next][0]) % K;
		int nextmask = bitset::add(mask, next);
		ret += dfs(nextmod, nextmask);
	}

	return ret;
}

int main() {
	FASTIO;

	cin >> N;						//max=15

	sets.resize(N);
	setslen.resize(N);
	digitmod.resize(51);

	for (int i = 0; i < N; i++) {
		cin >> sets[i];
		setslen[i] = sets[i].size();
	}
	cin >> K;						//max = 100

	dp.resize(1<<N, vector<int64>(K, -1)); 

	//init digitmod
	digitmod[0] = 1%K;
	for (int i = 1; i < digitmod.size(); i++) {
		digitmod[i] = (digitmod[i - 1] * 10) % K;
	}

	//modulos to elements
	for (auto& str : sets) {
		int mod = getModSTR(str, K);
		str = (char)mod;
	}

	int64 answers, allthing;		
	allthing = getFactorial(N);		//max 15!

	allmask = bitset::getAll(N);

	answers = dfs(0, 0);

	int64 gcd = ::gcd(answers, allthing);

	if (answers == 0)
		cout << "0/1";
	else
		cout << answers/gcd << "/" << allthing/gcd;

	return 0;
}
#endif 
