#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)
using int64 = long long;

enum
{
	MAX_IN = 10'000+1
};

int64 Ans[MAX_IN] = {  };
int64 Cost[MAX_IN] = { 0, };

int main()
{
	FASTIO;
	int N;
	cin >> N;

	int64 MAX = 0;

	M_Loop(i, 1, N+1)
	{
		cin >> Cost[i];
	}
	Ans[1] = Cost[1];
	Ans[2] = Cost[1] + Cost[2];

	M_Loop(j, 1, N + 1)
	{
		Ans[j] = ::max(Ans[j - 2] + Cost[j], Ans[j - 3] + Cost[j - 1] + Cost[j]);
		Ans[j] = ::max(Ans[j - 1], Ans[j]);
	}

	cout << Ans[N] << "\n";
}

#endif 