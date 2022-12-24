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
using float64 = double;
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

//º¤ÅÍ¿ÜÀû : »ï°¢Çü ³ÐÀÌ´Â ¿ÜÀûÀÇ Àý¹Ý
double GetTriangleArea(Pos p1, Pos p2, Pos p3) {
    return 0.5 * CCW(p1, p2, p3);
}

int main() {
	FASTIO;
    int N;
    cin >> N;

    for (int i = 0; i<N; i++) {
        cin >> positions[i].x >> positions[i].y;
    }
    double area = 0.0;
    for (int i = 1; i<N-1; i++) {
        
        area += GetTriangleArea( positions[0],positions[i],positions[i+1]);
    }
    printf("%.1lf", abs(area));

	return 0;
}
#endif 
                      
