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
};
bool operator==(Pos& A, Pos& B) {
	return A.x == B.x && A.y == B.y;
}
bool operator!=(Pos& A, Pos& B) {
	return !(A==B);
}

vector<Pos> p(4);

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
	return (p2.y-p1.y)/static_cast<double>((p2.x-p1.x));
}

double GetYwithX(Pos p1, Pos p2, double cx) {
	double grad = GetGrad(p1, p2);
	return grad*(cx - p1.x)+p1.y;
}

//todo :무한대의 기울기일 경우 문제 발생. 다른 교점의 좌표 구하는 알고리즘 필요 또는 경우의 수 나누기
Pos GetCrossP(Pos p1, Pos p2, Pos p3, Pos p4) {
	double gradA = GetGrad(p1, p2);
	double gradB = GetGrad(p3, p4);

	if (gradA!=gradB) {
		double cx = (gradA*p3.x-gradB*p1.x+p1.y-p3.y)/(gradA-gradB);
		return Pos{ cx, GetYwithX(p1,p2,cx) };
	}
	else { //is paralled
		if((p1==p3 && p2!=p4)||(p1==p4 && p2!=p3))
			return p1;
		if((p2==p3 && p1!=p4)||(p2==p4 && p1!=p3))
			return p2;
	}

	return Pos{MAX_X+1,0};
}


double CheckCCW(Pos p1, Pos p2, Pos p3, Pos p4) {
	double a = CCW(p1, p2, p3);
	double b = CCW(p1, p2, p4);

	double c = CCW(p3, p4, p1);
	double d = CCW(p3, p4, p2);

	if (a*b < 0 && c*d < 0)							//base
		return 1;

	if ((a*b==0 && (a||b)) || (c*d==0 && (c||d))) {	//one dot is on with other line
		if (!a)
			return IsMiddleP(p1, p2, p3);
		if (!b)
			return IsMiddleP(p1, p2, p4);
		if (!c)
			return IsMiddleP(p3, p4, p1);
		if (!d)
			return IsMiddleP(p3, p4, p2);
	}	

	if (!a && !b && !c && !d) {						//one line
		if ( IsMiddleP(p3, p4, p1) || IsMiddleP(p1, p2, p3) )
			return 1;

	}

	return 0;
}

int main() {
	FASTIO;

	for (auto& p : p) {
		cin >> p.x >> p.y;
	}
	for (int i = 0; i<4; i += 2) {
		if ((p[i].x > p[i+1].x) || ((p[i].x == p[i+1].x && p[i].y > p[i+1].y)))
			::swap(p[i], p[i+1]);		
	}

	cout << CheckCCW(p[0], p[1], p[2], p[3]) << endl;
	//int ret = CheckCCW(p[0], p[1], p[2], p[3]);

	//cout << ret << "\n";

	//if (ret) { //is crossed
	//	//todo
	//	Pos cp = GetCrossP(p[0], p[1], p[2], p[3]);
	//	if (cp.x <= MAX_X)
	//		cout << cp.x << " " << cp.y << "\n";
	//}
	
}
#endif 
                      
