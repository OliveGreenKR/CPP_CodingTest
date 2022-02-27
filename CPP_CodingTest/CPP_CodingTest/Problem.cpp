#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
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

int UP[MAX_IN] = { 0,1,}; //n이 끝인 최대증가수열길이
int DOWN[MAX_IN] = { 0,}; //n이 시작인 최대감소수열길이
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
		UP[j] = 1;
		M_Loop_sub(k, j, 0)
		{
			if (Cost[k] < mine)
				UP[j] = ::max(UP[k] + 1, UP[j]);
		}
	}

	M_Loop_sub(j, N, 0)
	{
		int mine = Cost[j];
		DOWN[j] = 1;
		M_Loop(k, j, N+1)
		{
			if (Cost[k] < mine)
				DOWN[j] = ::max(DOWN[k] + 1, DOWN[j]);
		}
	}

	M_Loop(i, 1, N + 1)
	{
		int& up = UP[i];
		up += DOWN[i]-1;
	}

	cout << *(::max_element(UP, UP + N + 1)) << "\n";
}

#endif 