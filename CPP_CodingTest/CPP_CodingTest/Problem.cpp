#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)

enum
{
	MAX_IN = 20
};
map<int, vector<int>> Board;
vector<bool> visited(MAX_IN, false);
int ANS = INT32_MAX;
int N;


void GetSUB()
{
	int T1 = 0, T2 = 0;
	M_Loop(now, 0, N)
	{
		M_Loop(mate, now + 1, N)
		{
			if (visited[now] && visited[mate])
			{
				T1 += Board[now][mate];
				T1 += Board[mate][now];
			}
			else if (!visited[now] && !visited[mate])
			{
				T2 += Board[now][mate];
				T2 += Board[mate][now];
			}
		}
	}

	ANS = ::min(ANS, abs(T1 - T2));
	return;
}

void ChoiceTeam(int cnt, int now = 0)
{
	if (cnt == N / 2)
	{
		GetSUB();
		return;
	}
	if (now >= N)
		return;

	if (visited[now] == false)
	{
		visited[now] = true;
		ChoiceTeam(cnt + 1, now + 1);
		visited[now] = false;
		ChoiceTeam(cnt, now + 1);
	}
}

int main()
{
	FASTIO;

	cin >> N;
	M_Loop(i, 0, N)
	{
		vector<int> tmp(N);
		M_Loop(j, 0, N)
		{
			cin >> tmp[j];
		}
		Board.emplace(i, tmp);
	}

	ChoiceTeam(0, 0);

	cout << ANS << "\n";

}
#endif 