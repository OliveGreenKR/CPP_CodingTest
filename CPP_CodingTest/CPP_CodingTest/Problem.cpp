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
	int Arr[100]; //Ÿ���� ť������ ���� ��ġ�� ����� �ִ�.
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
		int need = ::min(pos,rightneed);// �����ʿ��

		for (int i = index + 1; i < M; ++i) { 
			Arr[i] -= pos + 1;//�������¿ʹ� ������� ��� ������ġ�� �����ϰ� �������� �̵�(������ ��������)
			while (Arr[i] < 0) Arr[i] += N;//������ ����� �ɶ� ���� q.size��ŭ ���ϱ�(������ ���������� �Ѿ ��)
		}
		index++;
		cnt += need;
		N--; //ť�� size
	}
	printf("%d", cnt);
	return 0;
}
#endif 

