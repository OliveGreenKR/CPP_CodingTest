#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 10 +1
};

int DP[MAX_IN] = { 0,0,1,0 };  //N 일때 얻는 즐거움
int main()
{
	int N;
	cin >> N;

	M_Loop(i, 3, N + 1)
		DP[i] = ((i + 1) / 2* (i/2)) + DP[(i + 1)/2] + DP[i / 2];

	cout << DP[N] << "\n";
}

#endif 