#include "pch.h"
#ifdef BACK
#include <iostream>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN =  2'000'000'000
};

inline int Count(int n, int div)
{
	int ret = 0;
	int64 tok = div;
	while (tok <= n)
	{
		ret += n / tok;
		tok *= div;
	}
	return ret;
}

int GetAns(const int& n, const int& m)
{
	int top =::min(Count(n, 5) - Count(n - m, 5), Count(n, 2) - Count(n - m, 2));
	int bottom = Count(m, 5);
	int ret = top - bottom;
	if (ret < 0) ret = 0;
	return ret;
}
int main()
{
	FASTIO;
	int N, M;
	cin >> N >> M;
	cout << GetAns(N, M) << "\n";
}
#endif 
