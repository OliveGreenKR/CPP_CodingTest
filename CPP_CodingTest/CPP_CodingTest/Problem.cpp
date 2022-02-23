#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)
#define null_pair make_pair(-1,-1)
//�Ʒ��� �Լ��� �Ǻ���ġ�� ���� ��, 0 �� 1�� ���Ƚ����?
//������ȹ��

enum
{
	MAX_IN = 40
};

vector<pair<int, int>> Fibo = vector<pair<int, int>>(MAX_IN + 1, null_pair);
pair<int,int>& fibonacci(int n)
{
	auto& ret = Fibo[n];

	if (n == 0)
		ret = make_pair(1, 0);
	else if (n == 1)
		ret = make_pair(0, 1);

	else if (ret == null_pair)
	{
		ret.first = fibonacci(n - 1).first + fibonacci(n - 2).first;
		ret.second = fibonacci(n - 1).second + fibonacci(n - 2).second;
	}
	return ret;
}

int main()
{
	FASTIO;
	int T;
	cin >> T;

	M_Loop(i, 0, T)
	{
		int in;
		cin >> in;
		cout << fibonacci(in).first << " " << fibonacci(in).second << "\n";
	}
}

#endif 