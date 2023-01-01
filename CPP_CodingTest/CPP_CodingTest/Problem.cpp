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

double epsilon = 0.00000001;

double CCW(Pos p1, Pos p2, Pos p3) {
	double ccw = (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
	if (ccw == 0)
		return 0; //onLine
	else
		return ccw > 0 ? 1 : -1;
}
bool IsMiddleX(Pos p1, Pos p2, Pos p3) {
	return (::min(p1.x, p2.x) <= p3.x) && (p3.x <= ::max(p1.x, p2.x));
}
bool IsMiddleY(Pos p1, Pos p2, Pos p3) {
	return (::min(p1.y, p2.y) <= p3.y) && (p3.y <= ::max(p1.y, p2.y));
}

double CheckCCW(Pos p1, Pos p2, Pos p3, Pos p4) {
	double a = CCW(p1, p2, p3);
	double b = CCW(p1, p2, p4);

	double c = CCW(p3, p4, p1);
	double d = CCW(p3, p4, p2);

	if (a*b < 0  && c*d < 0)
		return 1;

	if (a == 0 || b == 0)
		if ((a == 0 && IsMiddleX(p1, p2, p3) && IsMiddleY(p1, p2, p3)) ||
			(b==0 && IsMiddleX(p1, p2, p4) && IsMiddleY(p1, p2, p4)))
			return 1;

	if (c == 0 || d == 0)
		if ((c == 0 && IsMiddleX(p3, p4, p1) && IsMiddleY(p3, p4, p1)) ||
			(d == 0 && IsMiddleX(p3, p4, p2) && IsMiddleY(p3, p4, p2)))
			return 1;

	return 0;
}

int main() {
	FASTIO;

	for (auto& p : p) {
		cin >> p.x >> p.y;
	}

	cout << CheckCCW(p[0], p[1], p[2], p[3]) << endl;

}
#endif 
                      
