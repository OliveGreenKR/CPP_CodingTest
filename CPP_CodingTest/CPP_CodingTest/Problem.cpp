#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)


#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

using int64 = long long;
int64 A, B, C;
int64 Ans=1;

int main()
{
	FASTIO
		cin >> A >> B >> C;
	while (B)
	{
		if (B % 2 > 0)
		{
			Ans *= A;
			Ans %= C;
		}
		B >>= 1;
		A *= A;
		A %= C;
	}
	cout << Ans;
}

#endif 
