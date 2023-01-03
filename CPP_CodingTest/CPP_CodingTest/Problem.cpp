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
	double x;
	double y;
};

enum : int64 {
	MAX_X =  1000000,
	NULLX = MAX_X+1,
};
bool operator==(Pos& A, Pos& B) {
	return A.x == B.x && A.y == B.y;
}
bool operator!=(Pos& A, Pos& B) {
	return !(A==B);
}

const double epsilon = 0.00000001;

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

bool IsMiddleP(Pos p1, Pos p2, Pos p3) {
	return IsMiddleX(p1, p2, p3)&&IsMiddleY(p1, p2, p3);
}

double GetGrad(Pos p1, Pos p2) {
	if (p1.x==p2.x)
		return 0;
	return (p2.y-p1.y)/static_cast<double>((p2.x-p1.x));
}

Pos GetCrossP(Pos p1, Pos p2, Pos p3, Pos p4) {

	double cx=NULLX, cy=0;
	double gradA = GetGrad(p1, p2);
	double gradB = GetGrad(p3, p4);

	if (p3.x == p4.x) {
		cx = p3.x;
		cy = gradA*(cx - p1.x)+p1.y;
		return Pos{cx,cy};
	}
	if (p1.x == p2.x) {
		cx = p1.x;
		cy = gradB*(cx - p3.x)+p3.y;
		return Pos{cx,cy};
	}

	if (gradA!=gradB) {
		cx = (gradA*p1.x-gradB*p3.x+p3.y-p1.y)/(gradA-gradB);
		cy = gradA*(cx - p1.x)+p1.y;
	}

	return Pos{ cx, cy };
}

Pos CheckCCW(Pos p1, Pos p2, Pos p3, Pos p4) {

	Pos ret = {MAX_X+1,0};
	double a = CCW(p1, p2, p3);
	double b = CCW(p1, p2, p4);

	double c = CCW(p3, p4, p1);
	double d = CCW(p3, p4, p2);

	if (a*b < 0 && c*d < 0)							//base
		ret = GetCrossP(p1, p2, p3, p4);

	if ((a*b==0 && (a||b)) || (c*d==0 && (c||d))) {	//one dot is on with other line
		if (!a && IsMiddleP(p1, p2, p3))
			ret = p3;
		if (!b && IsMiddleP(p1, p2, p4))
			ret = p4;
		if (!c && IsMiddleP(p3, p4, p1))
			ret = p1;
		if (!d && IsMiddleP(p3, p4, p2))
			ret = p2;
	}

	if (!a && !b && !c && !d) {						//one line
		if (IsMiddleP(p3, p4, p1) || IsMiddleP(p1, p2, p3)) {
			ret.y = 1;
			if (p1 == p4)
				ret = p4;
			if (p3 == p2)
				ret = p3;
		}
	}

	return ret;
}


int main() {
	FASTIO;

	vector<Pos> p(4);

	for (auto& p : p) {
		cin >> p.x >> p.y;
	}
	for (int i = 0; i<4; i += 2) {
		if ((p[i].x > p[i+1].x) || ((p[i].x == p[i+1].x && p[i].y > p[i+1].y)))
			::swap(p[i], p[i+1]);		
	}

	Pos ret = CheckCCW(p[0], p[1], p[2], p[3]);

	if (ret.x >= NULLX) {
		printf("%d", static_cast<int>(ret.y));
	}
	else
		printf("1\n%.16lf %.16lf",ret.x, ret.y);
}
#endif 
                      
