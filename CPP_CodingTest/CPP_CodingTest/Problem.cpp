#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
using float64 = long double;

queue<int> Ans;
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 1, N + 1)
		Ans.push(i);

	while (Ans.size() != 1)
	{
		Ans.pop();
		if (Ans.size() == 1)
			break;
		int tmp = Ans.front();
		Ans.pop();
		Ans.push(tmp);
	}
	cout << Ans.front() << "\n";
}

#endif 
