#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,n,st) for(int i=n;i>st;i--)
using int64 = long long;

enum
{
	MAX_IN = 100'000+1
};

int64 Arr[MAX_IN] = {};
int64 Ans[MAX_IN] = {}; //i���� �ִ� ������
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 1, N + 1)
	{
		cin >> Arr[i];
	}

	Ans[1] = Arr[1];
	M_Loop(i, 2, N + 1)
	{
		if(Ans[i-1]<0)//���� ���̻� ���ϸ� ����, ���ν���
			Ans[i] = Arr[i];
		else//���ϴ°� �̵��̹Ƿ� ���Ѵ�
		{
			Ans[i] = Ans[i - 1] + Arr[i];
		}
	}

	cout << *(::max_element(Ans + 1, Ans + N + 1)) << "\n";
}

#endif 