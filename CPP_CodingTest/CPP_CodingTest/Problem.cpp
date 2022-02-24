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
	MAX_IN = 100+1
};

long long Buff[MAX_IN] = {0,1,1,1,2,2,3,4,5,7,9};


long long GetAns(const int& N)
{
	if (N < 1)
		return 0;

	long long& ret = Buff[N];
	
	if (ret != 0)
		return ret;
	else
		ret = GetAns(N - 5)+ GetAns(N - 1);

	return ret;
}

int main()
{
	FASTIO;
	int T;
	cin >> T;
	M_Loop(i, 0, T)
	{
		int N;
		cin >> N;
		cout << GetAns(N) << "\n";
	}
}

#endif 