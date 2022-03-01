#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;

enum
{
	MAX_IN = 1000 +1,
	SK =1,
	CY =2
};

int64 DP[MAX_IN] = { 0 , CY,SK,CY};

int main()
{
	FASTIO;
	
	int N;
	cin >> N;

	M_Loop(i, 4, N + 1)
	{
		DP[i] = DP[i - 3] ^ 1;
	}

	if (DP[N] == CY)
		cout << "CY\n";
	else
		cout << "SK\n";
}

#endif 