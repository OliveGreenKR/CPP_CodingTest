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
	MAX_IN=20
};

vector<int> Board(MAX_IN, 0);
vector<bool> visited(MAX_IN, false);
int ANS = INT32_MAX;
int N;
int TOTAL=0;


void ChoiceTeam(int cnt, int now, int res )
{
	if (cnt == N / 2)
	{
		ANS = ::min(ANS, abs(res));
		return;
	}
	if (now < N - 1)
	{
		ChoiceTeam(cnt + 1, now + 1, res - Board[now]);
		ChoiceTeam(cnt , now + 1, res);
	}
}

int main()
{
	FASTIO;

	cin >> N;
	M_Loop(i, 0, N) 
	{
		M_Loop(j, 0, N)
		{
			int in;
			cin >> in;
			TOTAL += in;
			Board[i] += in; 
			Board[j] += in; 

		}
	}

	ChoiceTeam(0, 0, TOTAL);

	cout << ANS << "\n";

}

#endif 