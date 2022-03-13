#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
enum
{
	MAX_IN = 1000000
};
int Arr[MAX_IN];
int front, back, cnt = 0;
inline void Func1() { front++; }
inline void Func2(int n)
{
	M_Loop(i, 0, n)
	{
		Arr[back++] = Arr[front++];
		cnt++;
	}
}
inline void Func3(int n)
{
	M_Loop(i, 0, n)
	{
		Arr[--front] = Arr[--back];
		cnt++;
	}
}
int main()
{
	FASTIO;
	int N, M;
	cin >> N >> M;

	//초기값 설정
	front = MAX_IN/2; back = MAX_IN / 2;
	M_Loop(i, 1, N + 1)
		Arr[back++] = i;
	//타겟
	M_Loop(i, 0, M)
	{
		int num;
		cin >> num;
		if (Arr[front] == num)
		{
			Func1();
			continue;
		}
		int index = front;
		while (Arr[index] != num)
			index++;
		(index - front) <= (back - index) ? Func2(index - front) : Func3(back - index);
		Func1();
	}
	cout << cnt;
	return 0;
}
#endif 

