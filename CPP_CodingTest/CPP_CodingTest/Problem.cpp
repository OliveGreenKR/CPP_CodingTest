#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;


int64 N, K, W, V, D[100001] = { 0, };
#include<stdio.h>
int main()
{
	FASTIO;
	cin >> N >> K;
	M_Loop(i, 0, N)
	{
		cin >> W >> V;
		M_Loop_sub(j, K, W-1)
		{
			D[j] = ::max(D[j], D[j - W] + V);
		}
	}
	cout << D[K] << "\n";
	return 0;
}

#endif 