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
	Red = 0,
	Green = 1,
	Blue = 2,
	MAX_IN = 1000+1
};
int N;
int64 ans[MAX_IN][3] = {0,};

int main()
{
	FASTIO;
	cin >> N;
	int cost[3] = {};
	M_Loop(i, 1, N+1)
	{
		cin >> cost[Red] >> cost[Green] >> cost[Blue];
		ans[i][Red] = ::min(ans[i - 1][Green], ans[i - 1][Blue]) + cost[Red];
		ans[i][Green] = ::min(ans[i - 1][Red], ans[i - 1][Blue]) + cost[Green];
		ans[i][Blue] = ::min(ans[i - 1][Red], ans[i - 1][Green]) + cost[Blue];
	}
	
	cout << ::min(ans[N][Red], ::min(ans[N][Green], ans[N][Blue])) << "\n";
	return 0;
}

#endif 