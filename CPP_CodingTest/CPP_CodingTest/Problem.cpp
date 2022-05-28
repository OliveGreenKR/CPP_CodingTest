#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_IN = 1'000+1
};

struct Pos
{
	int y; int x;
};
int N, W;
int dp[MAX_IN][MAX_IN]; //dp, 최소값까지 남은거리
Pos arr[MAX_IN];

int getDist(int nowy, int nowx, int disty, int distx)
{
	return (abs(distx-nowx)+abs(disty-nowy));
}

int getDp(int first, int second)
{
	if (first==W||second==W) return 0;
	if (dp[first][second]!=-1) return dp[first][second];

	int next = ::max(first, second)+1;
	int dist1, dist2;

	dist1 = first==0 ? getDist(1, 1, arr[next].y, arr[next].x) : getDist(arr[first].y, arr[first].x, arr[next].y, arr[next].x);
	dist2 = second==0 ? getDist(N, N, arr[next].y, arr[next].x) : getDist(arr[second].y, arr[second].x, arr[next].y, arr[next].x);
	
	return dp[first][second] = ::min(dist1+getDp(next, second), dist2+getDp(first, next)); //움직여야하는 거리 기록
}

void Track(int first, int second)
{
	if (first==W||second==W) return;
	
	int next = ::max(first, second)+1;
	int dist1, dist2;

	dist1 = first==0 ? getDist(1, 1, arr[next].y, arr[next].x) : getDist(arr[first].y, arr[first].x, arr[next].y, arr[next].x);
	dist2 = second==0 ? getDist(N, N, arr[next].y, arr[next].x) : getDist(arr[second].y, arr[second].x, arr[next].y, arr[next].x);

	if (dp[next][second]+dist1<dp[first][next]+dist2)//움직여야하는 거리 비교
	{
		cout<<1<<"\n";
		Track(next, second);
	}
	else
	{
		cout<<2<<"\n";
		Track(first, next);
	}
}

int main()
{
	FASTIO;
	::memset(dp, -1, sizeof(dp));
	cin>>N>>W;
	for (int i = 1; i<=W; i++)
		cin>>arr[i].y>>arr[i].x;
	cout<<getDp(0, 0)<<"\n";
	Track(0,0);
	return 0;
}
#endif 

