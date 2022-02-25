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

int64 Ans[MAX_IN][MAX_IN] = {  }; //[처음으로 N고름][그뒤]
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
	M_Loop(j, 1, N + 1)
	{
		Ans[j][j] = Cost[j];
		Ans[j][j+1] = Cost[j] + Cost[j + 1];
		M_Loop(i, j+2, N + 1)
		{
			Ans[j][i] = ::max(Ans[j][i - 2] + Cost[i], Ans[j][i - 3] + Cost[i - 1] + Cost[i]);
			MAX = ::max(MAX, Ans[j][i]);
		}
	}
	cout << MAX << "\n";
}

#endif 
//이거는 순서대로일때, 문제는 조합으로 해야한다.(순서없음)