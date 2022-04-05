#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
    MAX_IN = 30+1,
	MAX_W = 500 * 30+1
};
int N;
int arr[MAX_IN];
bool dp[MAX_IN][MAX_W];  // [i][j] = i번째 추를 사용한 상태에서 j무게를 만들수 있는지
void GetAns(int i, int w) 
{
	if (i > N || dp[i][w]) return;
	dp[i][w] = true;

	GetAns(i + 1, w + arr[i]);
	GetAns(i + 1, ::abs(w - arr[i]));
	GetAns(i + 1, w);
}
int main()
{
	FASTIO;
    cin >> N;
	M_Loop(i, 0, N)
		cin >> arr[i];
	GetAns(0, 0);
	int M;
	cin >> M;
	M_Loop(i, 0, M)
	{
		int w;
		cin >> w;
		if (w > (MAX_W-1) || !dp[N][w]) cout << "N";
		else cout << "Y";
		cout << " ";
	}
	return 0;
}
#endif 




