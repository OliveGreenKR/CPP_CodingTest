#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)
using int64 = long long;

enum
{
	MAX_IN = 100 + 1,
	ANS_DIV = 1'000'000'000
};
int64 Num[10] = { 0,1,1,1,1,1,1,1,1,1 };//끝자릿수 개수
int main()
{
	FASTIO;

	int N;
	cin >> N;
	M_Loop(k, 2, N + 1)
	{
		int64 tmp[10];
		::copy(Num, Num + 10, tmp);
		M_Loop(i, 0, 10)
		{
			if (i == 0)
				Num[i] = tmp[i + 1] % ANS_DIV;
			else if (i == 9)
				Num[i] = (tmp[i - 1]) % ANS_DIV;
			else
				Num[i] = (tmp[i - 1] + tmp[i + 1]) % ANS_DIV;
		}
	}

	int64 sum = 0;
	M_Loop(i, 0, 10)
	{
		sum += Num[i];
	}
	cout << sum % ANS_DIV << "\n";
}

#endif 