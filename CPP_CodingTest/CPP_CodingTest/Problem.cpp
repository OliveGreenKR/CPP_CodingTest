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
#include <math.h>

using namespace std;
using int64 = long long;
using Pos = pair<int, int>; //[x][y]
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

enum
{
    MAX_IN = 10'000+1,
};
int N;
vector<Pos> poses;

double IntegralFirst(const double& a, const double& b, const Pos& p1, const Pos& p2)
{
    //p1과 p2 까지 y= ax+b를 적분.
    double ret = 0.f;
    auto func = [&](const Pos& p) {
        return (a / 2) * pow((p.first), 2) + b * (p.first);
    };
    ret = func(p2) - func(p1);
    return ret;
}

pair<int,int> getFunc(const double& a, const double& b, const Pos& p1, const Pos& p2) {
    //기준직선 ax+b 에 대한 p1과 p2의 직선함수 y` = a`x + b`를 구한다.
    pair<int, int> coefficient; //{a`,b`}

    double tilt = (p2.second - p1.second) / static_cast<double>(p2.first - p1.first);

    coefficient.first = tilt;
    coefficient.second = p1.second - tilt * p1.first;
    return coefficient;
}

void getAns()
{
    //정렬된 좌표를 기준으로 기준 직선 구하기
    auto floor = getFunc(0, 0, poses[0], poses[N - 1]);

    double ret = 0.f;
    for (int i = 0; i < N - 1; i++)
    {
        auto line = getFunc(floor.first, floor.second, poses[i], poses[i + 1]);
        ret += abs(IntegralFirst(line.first, line.second, poses[i], poses[i + 1]));
    }

    
    cin.precision(2);
    cout << ret << "\n";
}
int main() {
	FASTIO;
    cin >> N;
    poses.resize(N);
    for (int i = 0; i < N; i++)
    {
        Pos& p = poses[i];
        cin >> p.first >> p.second;
    }

    ::sort(poses.begin(), poses.end()); //x좌표 기준으로 정렬.

    getAns();
   
	return 0;
}
#endif 
                      
