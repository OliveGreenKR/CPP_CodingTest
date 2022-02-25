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

int64 Ans[MAX_IN] = { 0, };
int64 Cost[MAX_IN] = { 0, };

int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 1, N+1)
	{
		cin >> Cost[i];
	}
	Ans[1] = Cost[1];
	Ans[2] = Cost[2]+Cost[1];

	M_Loop(i, 3, N + 1)
	{
		Ans[i] = ::max(Ans[i - 2] + Cost[i], Ans[i - 3] + Cost[i - 1] + Cost[i]);
	}
	cout << *(::max_element(Ans, Ans + N)) << "\n";
}

#endif 