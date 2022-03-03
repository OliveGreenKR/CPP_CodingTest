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

int main()
{
	FASTIO;
	int A, B;
	cin >> A >> B;
	int Mul = A * B;
	while (B)
	{
		int tmp = B;
		B = A % B;
		A =tmp;
	}
	cout << A << "\n" << Mul / A << "\n";
}

#endif 
