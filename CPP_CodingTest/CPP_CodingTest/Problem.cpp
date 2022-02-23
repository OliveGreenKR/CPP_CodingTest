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
	MAX_IN = 51
};

int Buff[MAX_IN][MAX_IN][MAX_IN] ={1,};

int& W(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return Buff[0][0][0];
	}
	int& ret = Buff[a][b][c];

	if (ret != 0)
		return ret;
	else if (a > 20 || b > 20 || c > 20)
		ret =  W(20, 20, 20);
	else if (a < b && b < c)
		ret =  W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
	else
		ret =  W(a-1, b, c) + W(a-1, b- 1, c) + W(a-1, b, c-1) - W(a - 1, b-1, c - 1);
	return ret;
}
int main()
{
	FASTIO;
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}
}

#endif 