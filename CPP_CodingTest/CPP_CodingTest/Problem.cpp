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
int64 OilPrice[MAX_IN];//���ʹ� ����
int64 ToGo[MAX_IN];//���α���
int main()
{
	FASTIO;
	cin >> N;

	M_Loop(i, 0, N - 1)
		cin >> ToGo[i];
	M_Loop(i, 0, N)
		cin >> OilPrice[i];

	int64 ANS = 0;
	int64 now = OilPrice[0];//���缱�õ� ���� �� ���ϰ���
	int64 lenSum = 0; //����
	M_Loop(i,0,N-1)
	{
		if (now > OilPrice[i]) 
		{
			ANS += now * lenSum;
			lenSum = 0; //�ʱ�ȭ
			now = OilPrice[i]; //����
		}
		lenSum += ToGo[i];
	}
	ANS += now * lenSum;
	cout << ANS << "\n";
}

#endif 