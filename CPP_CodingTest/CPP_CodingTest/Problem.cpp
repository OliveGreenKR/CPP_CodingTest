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
	int64 now = OilPrice[0];//현재선택된 리터 당 오일가격
	int64 lenSum = 0; //길이
	M_Loop(i,0,N-1)
	{
		if (now > OilPrice[i]) 
		{
			ANS += now * lenSum;
			lenSum = 0; //초기화
			now = OilPrice[i]; //선택
		}
		lenSum += ToGo[i];
	}
	ANS += now * lenSum;
	cout << ANS << "\n";
}

#endif 