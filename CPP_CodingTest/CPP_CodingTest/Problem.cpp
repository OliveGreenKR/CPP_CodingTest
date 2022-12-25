#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
using int64 = long long;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

enum
{
    MAX_IN = 10'000+1,
};
struct Pos {
    int64 x;
    int64 y;
};

vector<Pos>positions(MAX_IN);

double CCW(Pos p1, Pos p2, Pos p3) {
	return (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
}

int main() {
	FASTIO;
    int N=3;

    for (int i = 0; i<N; i++) {
        cin >> positions[i].x >> positions[i].y;
    }
    double ccw = CCW(positions[0],positions[1],positions[2]);
    int ans = 0;
    if (ccw >0) ans = 1;
    else if (ccw<0) ans = -1;

    printf("%d", ans);

	return 0;
}
#endif 
                      
