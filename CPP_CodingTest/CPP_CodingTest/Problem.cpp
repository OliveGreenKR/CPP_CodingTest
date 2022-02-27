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
	MAX_IN = 1'00+1
};

pair<int, int> Line[MAX_IN] = {};
int Ans[MAX_IN] = {}; //idx가 끝인 증가수열의 길이
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 1, N+1)
	{
		cin >> Line[i].first >> Line[i].second;
	}
	::sort(Line + 1, Line + N + 1);

	M_Loop(i, 1, N + 1)
	{
		Ans[i] = 1;
		int& mine = Line[i].second;
		M_Loop_sub(j, i, 0)
		{
			if (Line[j].second < mine)
				Ans[i] = ::max(Ans[i], Ans[j] + 1);
		}
	}
	cout << N - *(::max_element(Ans + 1, Ans + N +1)) << "\n";
}

#endif 