#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define POW(x) (std::pow((x),2))

using namespace std;
using int64 = long long;


struct Pos {
	double x;
	double y;
};

double GetDistance(Pos& A, Pos& B) {
	return sqrt(POW(A.x-B.x) + POW(A.y-B.y));
}

double GetTimeToHome(Pos& Home, Pos& now, const double& D, const double& T) {

	double dist = GetDistance(now, Home);
	int jumpcnt = (int)(dist/D);

	double time = dist; //only walk
	dist -= jumpcnt*D;

	if ( D <= T ) return time;

	if (jumpcnt > 0) 
		time = ::min(time, ::min(jumpcnt*T+dist, (jumpcnt+1)*T));
	else 
		time = ::min(time, ::min(D-dist+T, 2*T));
	
	return time;
}

int main() {
	FASTIO;

	Pos now;
	Pos Home = Pos{0,0};
	double T, D;

	cin >> now.x >> now.y 
		>> D >> T; 

	printf("%.13lf",GetTimeToHome(Home, now, D, T));
	
	return 0;
}
#endif 
                      