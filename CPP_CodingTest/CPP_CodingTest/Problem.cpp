#include "pch.h"
#ifdef BACK
#include <iostream>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)

enum
{
	GMAX = 8 +1
};

bool Node[GMAX] = { false, };
int  ans[GMAX] = {};

void DFS(int cnt, const int& N ,const int& M)
{
	if (cnt == M)
	{
		M_Loop(i, 0, M)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	M_Loop(i, 1, N+1)
	{
		if (!Node[i])
		{
		ans[cnt] = i;
			M_Loop(j, 1, i)
				Node[j] = true;

		DFS(cnt+1, N, M);
			M_Loop(j, 1, i)
				Node[j] = false;
		}
	}
}
///ddddd
int main() {
	FASTIO;

	int N, M;
	cin >> N >> M;

	DFS(0, N, M);
}

#endif 