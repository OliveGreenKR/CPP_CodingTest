#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_PI (3.14159265358979323846)
#define POW(x) (std::pow((x),2))

using namespace std;
using int64 = long long;


struct Pos {
	double x;
	double y;
};

struct Circle {
	Pos center;
	double r;
};

bool operator<(const Circle& A, const Circle& B) {
	return A.r < B.r;
}

double GetDistance(Pos& A, Pos& B) {
	return sqrt(POW(A.x-B.x) + POW(A.y-B.y));
}

double GetCircleArea(const Circle& A) {
	return POW(A.r)*M_PI;
}

double GetInterSection(Circle& A, Circle& B) {
	double d = GetDistance(A.center, B.center);
	double& r1 = A.r;
	double& r2 = B.r;

	if (d >= r1+r2)
		return 0;

	if (d <= abs(r1-r2))
		return GetCircleArea(::min(A, B));

	//»çÀÕ°¢
	double alpha = acos((POW(r1) + POW(d) - POW(r2))	/	(2*r1*d)); 
	double beta  = acos((POW(r2) + POW(d) - POW(r1))	/	(2*r2*d));

	//ºÎºÐ¿øÀÇ ³ÐÀÌ - ºñ±³Â÷³ÐÀÌ(»ï°¢Çü)
	return (GetCircleArea(A)*alpha/M_PI + GetCircleArea(B)*beta/M_PI) - (POW(r1)*sin(2*alpha) + POW(r2)*sin(2*beta))/2;
}

int main() {
	FASTIO;

	int N = 2;

	vector<Circle> circles(N);
	for (auto& c :  circles){
		cin >> c.center.x >> c.center.y >> c.r;
	}
	printf("%.3lf", GetInterSection(circles[0], circles[1]));
}
#endif 
                      