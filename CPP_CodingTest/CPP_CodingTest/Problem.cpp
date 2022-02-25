#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)
using int64 = long long;

enum
{
	MAX_IN = 300 +1
};

int64 Ans[MAX_IN] = {0,};
int64 Stair[MAX_IN] = {0,};

int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 1, N+1)
	{
		cin >> Stair[i];
		if (i > 1)
		{
			Ans[i] = ::max(Ans[i - 2] + Stair[i], Ans[i - 3] + Stair[i - 1] + Stair[i]);
		}
		else
			Ans[i] = Stair[i];
	}
	cout << Ans[N] << "\n";
}

#endif 