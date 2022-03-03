#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;


enum
{
	MAX_IN = 100'000
};

int N;
int64 OilPrice[MAX_IN];//리터당 가격
int64 ToGo[MAX_IN];//도로길이
int main()
{
	FASTIO;
	cin >> N;
	M_Loop(i, 0, N - 1)
		cin >> ToGo[i];
	M_Loop(i, 0, N)
		cin >> OilPrice[i];

	int64 ANS = 0;
	int64 now = OilPrice[0];
	M_Loop(i,0,N-1)
	{
		now = ::min(now, OilPrice[i]);
		ANS += now * ToGo[i];
	}
	cout << ANS << "\n";
}

#endif 