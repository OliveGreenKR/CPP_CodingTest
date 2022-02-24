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
int64 MIN = INT64_MAX;
int64 sel = 0;
vector<pair<int, vector<int>>> Buff(MAX_IN, make_pair(0,vector<int>(3, 0)));

void GetAns(const int& cnt,int ex =-1)
{
	if (cnt == N)
	{
		MIN = min(MIN, sel);
		return;
	}
	M_Loop(i, 0, 3)
	{
		if (i == ex)
			continue;
		else
		{
			sel += Buff[cnt+1].second[i];
			GetAns(cnt + 1, i);
			sel -= Buff[cnt+1].second[i];
		}
	}
	return;
}

int main()
{
	FASTIO;
	cin >> N;
	M_Loop(i, 1, N+1)
	{
		int R, G, B;
		cin >> R >> G >> B;
		Buff[i].second = vector<int>{R,G,B};
	}
	/*cout << GetAns(N) << "\n";*/
	GetAns(0);
	cout << MIN << "\n";
	return 0;
}

#endif 