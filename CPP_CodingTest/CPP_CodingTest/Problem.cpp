#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)


#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
#define MAX_IN  40'000'001LL 
#define P 1'000'000'007LL
int64 Num1, Num2, half;
int64 GetPow(int64& m, int64 k)
{
	if (k == 0)
		return 1;
	if (k % 2)
		return m * GetPow(m, k - 1) % P;

	half = GetPow(m, k / 2) % P;
	return (half * half)% P;
}

int64 N, K;
int main()
{
	FASTIO;
	cin >> N >> K;

	Num1 = 1;
	M_Loop_sub(i, N, N-K)
		Num1 = (Num1 * i) % P;

	Num2 = 1;
	M_Loop(i, 1, K+1)
		Num2 = (Num2 * i) % P;

	Num2 = GetPow(Num2, P - 2);
	cout << Num1 * Num2 % P;
}

#endif 
