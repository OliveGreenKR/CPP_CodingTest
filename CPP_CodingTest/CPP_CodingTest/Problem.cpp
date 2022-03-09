#include "pch.h"
#ifdef BACK
#include <iostream>
#include <stack>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 1'000'000
};
stack<int> cache;
int inputs[MAX_IN] = {};
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 0, N)
		cin >> inputs[i];
	cache.push(inputs[N-1]);
	inputs[N - 1] = -1;
	M_Loop_sub(i, N - 2, -1)
	{
		int& now = inputs[i];
		int tmp = now;
		while (now >= cache.top())
		{
			cache.pop();
			if (cache.empty())
			{
				now = -1;
				break;
			}
		}
		if (now != -1)
			now = cache.top();
		cache.push(tmp);
	}
	M_Loop(i, 0, N)
		cout << inputs[i] << " ";
}
#endif 
