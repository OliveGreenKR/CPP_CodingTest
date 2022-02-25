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
	MAX_IN = 1'000'000+1
};

int64 Ans[MAX_IN] = {0,0,1,1,};

int main()
{
	FASTIO;

	int N;
	cin >> N;
	M_Loop(i, 4, N + 1)
	{
		if(i%3 == 0)
			Ans[i] = ::min(Ans[i - 1] + 1, Ans[i / 3] + 1);
		else if (i%2==0)
			Ans[i] = ::min(Ans[i - 1] + 1, Ans[i / 2] + 1);
		else
			Ans[i] = Ans[i - 1]+1;
	}
	cout << Ans[N] << "\n";
}

#endif 