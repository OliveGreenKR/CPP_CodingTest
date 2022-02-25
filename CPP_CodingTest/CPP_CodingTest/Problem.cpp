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
	MAX_IN = 500 + 1
};

int64 Ans[MAX_IN][MAX_IN] = {};

int main()
{
	FASTIO;
	
	int N;
	cin >> N;
	int line[MAX_IN] = {};
	int check = 0;
	M_Loop(i, 1, N+1)
	{
		M_Loop(j, 1, i+1)
		{
			cin >> line[j];
			Ans[i][j] = ::max(Ans[i - 1][j], Ans[i - 1][j - 1]) + line[j];
		}
	}

	cout << *(::max_element(Ans[N], Ans[N] + MAX_IN)) << "\n";

}

#endif 