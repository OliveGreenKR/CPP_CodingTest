#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)
#define null_pair make_pair(-1,-1)

enum
{
	MAX_IN = 1'000'000
};

int Buff[MAX_IN];

int Combi(int n, int k)
{
	if (k == 1)
		return n;
	if (k > n || k<=0 || n<=0)
		return 0;
	if (k == n)
		return 1;
	return Combi(n - 1, k-1) + Combi(n-1, k);
}

int& GetAns(const int& N)
{
	int& ret = Buff[N];

	if (ret != 0)
		return ret;
	if (N % 2 == 0)
	{

	}
	else
	{
		ret = GetAns(N - 1) + 1;
	}

}

int main()
{
	FASTIO;

	int N, K;
	cin >> N >> K;
	//GetAns(N);
	cout << Combi(N, K);
}

#endif 