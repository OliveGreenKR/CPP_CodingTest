#include "pch.h"
#ifdef BACK

#include <vector>
#include <list>
#include <algorithm>
#include<string>

#include <cmath>
#include <iostream>
using namespace std;

/* �־��� N���� ������ �Ҽ��� ������ ����ϼ��� */

static int cnt = 0;

void IsPrime(const int& N)
{
	if(N <= 1)
		return;

	for (int i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			cnt--;
			break;
		}
	}
	cnt++;
}

int main()
{
	

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		IsPrime(N);
	}
	
	cout << cnt << endl;
}
#endif