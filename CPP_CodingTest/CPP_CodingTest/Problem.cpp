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
int allmask;

vector<string> sets;
vector<vector<int>> dp;  //[mask][mod] = [사용한원소][현재mod값]의 정답 수

uint64 getFactorial(int x) {
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
uint64 dfs(int now, int mask) {			
	//순열완성
	if (mask == allmask) {
		if (now==0)
			return 1;
		return 0;
	}

	int& ret = dp[mask][now];
	//방문검사
	if (ret != -1)
		return ret;
	//초기화
	ret = 0;
	for (int next = 0; next < N; next++) {
		if (bitset::check(mask, next))
			continue;
		//todo
		int nextmask = bitset::add(mask, next);
		int nextmod = (now+(int)sets[next][0]) % K;
		ret += dfs(nextmod, nextmask);
	}

	return ret;
}


int main() {
	FASTIO;

	cin >> N;						//max=15

	sets.resize(N);
	dp.resize(1<<N, vector<int>(N, -1)); 

	for (int i = 0; i < N; i++) {
		cin >> sets[i];
	}
	cin >> K;						//max = 100

	uint64 answers, allthing;		

	allthing = getFactorial(N);		//max 15!

	//modulos to elements
	for (auto& str : sets) {
		int mod = getModSTR(str, K);
		str = (char)mod;
	}
	
	allmask = bitset::getAll(N);

	return 0;
}

/*
uint64_t value;
std::istringstream iss("18446744073709551610");
iss >> value;
*/


/*
	//modulos to elements
	for (auto& str : sets) {
		int mod = getModSTR(str, K);
		string modstr = ::to_string(mod);
		int zeros = str.size() - modstr.size();
		str =  string(zeros, '0');
		str += modstr;
	}
*/
#endif 
