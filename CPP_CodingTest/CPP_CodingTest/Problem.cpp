#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
    MAX_IN = 500+2,
};
int map[MAX_IN][MAX_IN];
int dp[MAX_IN][MAX_IN]; 
int N, M;

int dir[][2] = {
    {-1,0}, //up
    {0,1},  //right
    {1,0},  //down
    {0,-1}  //left
};

inline int dfs(int y, int x) //(y,x)에서 목적지까지가는 경우의수
{
    if (y == M && x == N)
        return 1;
    if (y > M || x > N || y < 1 || x < 1)
        return 0;
    int& now = dp[y][x];
    if (now != -1)
        return now;
    now = 0;
    int h = map[y][x];
    M_Loop(i, 0, 4)
    {
        int* dr = dir[i];
        int nexty = y + dr[0];
        int nextx = x + dr[1];
        int nexth = map[nexty][nextx];
        if ( nexth && (h > nexth))
        {
            now += dfs(nexty, nextx);
        }
    }
    return now;
}
int main()
{
	FASTIO;
    cin >> M >> N;
    ::memset(dp, -1, MAX_IN * MAX_IN*sizeof(int));

    M_Loop(i, 1, M+1)
    {
        M_Loop(j, 1, N+1)
        {
            cin >> map[i][j];
        }
    }
    cout << dfs(1, 1);

	return 0;
}
#endif 

/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
    MAX_IN = 9
};
int main()
{
    FASTIO;

    int arr[9];
    int MAX = INT32_MIN;
    int idx = 0;
    M_Loop(i, 1, MAX_IN+1)
    {
        int tmp;
        cin >> tmp;
        if (MAX < tmp)
        {
            MAX = tmp;
            idx = i;
        }
    }
    cout << MAX << "\n" << idx;
}*/


