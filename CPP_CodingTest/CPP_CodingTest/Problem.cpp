#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,n,st) for(int i=n;i>st;i--)
using int64 = long long;

enum
{
	MAX_IN = 1'000+1
};

int Ans[MAX_IN] = { 0,1,}; //N까지 일때 가장 긴 증가부분수열의 길이
int Cost[MAX_IN] = { 0, };

int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 1, N+1)
	{
		cin >> Cost[i];
	}

	M_Loop(j, 2, N + 1)
	{
		int mine = Cost[j];
		Ans[j] = 1;
		M_Loop_sub(k, j, 0)
		{
			if (Cost[k] < mine)
				Ans[j] = ::max(Ans[k] + 1, Ans[j]);
		}
	}
	cout << *(::max_element(Ans, Ans + N+1)) << "\n";
}

#endif 