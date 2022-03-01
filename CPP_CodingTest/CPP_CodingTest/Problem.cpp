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
	MAX_IN = 10000 +1,
};

float64 DP[MAX_IN] = {};
float64 Arr[MAX_IN] = {};

int main()
{
	int N;
	cin >> N;
	M_Loop(i, 1, N+1)
	{
		cin >> Arr[i];
	}

	DP[1] = Arr[1];
	M_Loop(i, 2, N + 1)
	{
		DP[i] = ::max(DP[i - 1] * Arr[i], Arr[i]);	//곱하다가 1미만이 되면 자기자신 선택
	}
	cout.precision(3);
	cout.setf(ios::fixed, ios::floatfield);
	
	cout << *(::max_element(DP + 1, DP + N + 1)) << "\n";
}

#endif 