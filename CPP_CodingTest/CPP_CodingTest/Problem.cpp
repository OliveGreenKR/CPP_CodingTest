#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <deque>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

enum
{
	MAX_IN = 50+1
};
int Arr[110];
//pair<int, int> Arr[110]; //[val][idx]

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
		Arr[--front]= Arr[--back];
		cnt++;
	}
}
int cache[MAX_IN];
int main() //pop-push 연산 최소화
{
	FASTIO;
	int N, M;
	cin >> N >> M;

	//초기값 설정
	front = 50; back = 50;
	M_Loop(i,1,N + 1) 
		Arr[back++] = i; //val
	
	M_Loop(i, 0, M)
		cin >> cache[i]; //뽑을 숫자

	int idx = 0;
	while (idx<M)
	{
		const int target = cache[idx];
		int tmp = front;
		if (Arr[tmp] == target)
		{
			Func1();
			idx++;
			continue;
		}
		while (Arr[tmp] != target)
			tmp++;

		(tmp - front) <= back - tmp ? Func2(tmp-front) : Func3(back-tmp);
		idx++;
	}
	cout << cnt;
	return 0;
}



#endif 
