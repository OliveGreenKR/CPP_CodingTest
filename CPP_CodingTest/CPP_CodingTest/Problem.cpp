#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
using int64 = long long;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

struct Pos {
	int64 x;
	int64 y;
};

vector<Pos> p(4);

double CCW(Pos p1, Pos p2, Pos p3) {
	double ccw = (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
	return ccw > 0 ? 1 : -1;
}

int main() {
	FASTIO;
	for (auto& p : p) {
		cin >> p.x >> p.y;
	}

	int l1 = CCW(p[0], p[1], p[2]) * CCW(p[0], p[1], p[3]); 
	int l2 = CCW(p[2], p[3], p[0]) * CCW(p[2], p[3], p[1]); 
	
	int ret = 0;
	if (l1<0 && l2 <0)
		ret = 1;
	cout << ret  << endl;
}
#endif 
                      
