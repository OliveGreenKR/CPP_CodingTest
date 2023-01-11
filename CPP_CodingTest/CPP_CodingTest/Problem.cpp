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


class Bitset32 {
	
public:
	Bitset32(int max) : _maxcnt(max) {};
public:
	void add(int x) {
		_bitset |= (1<<x);
	}
	void remove(int x) {
		_bitset &= (~(1<<x));
	}
	bool check(int x) {
		return _bitset & (1<<x) ? 1 : 0 ;
	}
	void toggle(int x) {
		_bitset ^= (1<<x);
	}
	void makeEmpty(int x) {
		_bitset = 0;
	}
	bool isAll(int count) {
		return _bitset == ((1 << _maxcnt) - 1) ? 1 : 0;
	}
	int getBitset() {
		return _bitset;
	}

private:
	int _bitset = 0;
	int _maxcnt;
};

vector<vector<int>> cost;
vector<vector<int>> dp; //[i][j] 까지 최소값
Bitset32 jobcheck(20);

int MIN_VAL = INT_MAX;


enum {
	MAX_M = 10'000
};



int dfs(int worker, Bitset32& jobcheck) {

}

int main() {
	FASTIO;
	int N;
	cin >> N;

	cost.resize(N, vector<int>(N)); //job cost
	dp.resize(N, vector<int>(N, INT_MAX));
	jobcheck = Bitset32(N);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}



	return 0;
}
#endif 
                      