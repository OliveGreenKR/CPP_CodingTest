#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

int main(void)
{
	int N, M;
	int Arr[100]; //타겟의 큐에서의 현재 위치가 담겨져 있다.
	scanf("%d %d", &N, &M);
	int arrsize_h = N / 2;

	for (int i = 0; i < M; ++i) {
		scanf("%d", &Arr[i]);
		Arr[i] -= 1;
	}
	int index = 0;
	int cnt = 0;
	while (index < M) {
		int pos = Arr[index];
		int rightneed = N - pos;
		int need = ::min(pos,rightneed);// 연산필요수

		for (int i = index + 1; i < M; ++i) { 
			Arr[i] -= pos + 1;//연산형태와는 관계없이 모든 원소위치를 동일하게 왼쪽으로 이동(뺄려는 원소제외)
			while (Arr[i] < 0) Arr[i] += N;//음수면 양수로 될때 까지 q.size만큼 더하기(음수면 오른쪽으로 넘어간 것)
		}
		index++;
		cnt += need;
		N--; //큐의 size
	}
	printf("%d", cnt);
	return 0;
}
#endif 

