#include "pch.h"
#ifdef BACK

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)
enum
{
	_MAX = 8001,
	_HALF = (_MAX) / 2
};
using namespace std;
vector<int> InputCount(_MAX, 0); //횟수
vector<int> Vsort;

int main()
{
	int MAX = INT32_MIN, MIN = INT32_MAX; //최대값 최소값

	int N;//원소개수
	cin >> N;

	int SUM = 0;//합계
	int MaxCnt = 0; // 최대 회수

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		SUM += input;
		if (input > MAX)
			MAX = input;
		if (input < MIN)
			MIN = input;
		int cnt = ++InputCount[input + _HALF];
		if (cnt > MaxCnt)
			MaxCnt = cnt;
	}
	//벡터 정렬
	int Freq = INT32_MAX; //최빈값
	for (int idx = 0; idx < _MAX; idx++)
	{
		int cnt = InputCount[idx];
		int tmp = idx - _HALF;
		if (cnt != 0)
		{
			for (int i = 0; i < cnt; i++)
				Vsort.push_back(tmp);
		}
		if (cnt == MaxCnt)
		{
			if (Freq != INT32_MAX)
			{
				MaxCnt++;
			}
			Freq = tmp;
		}

	}
	//산술평균
	double avg = SUM / static_cast<double>(N);
	if (-1 < avg && avg < 1) avg = 0;
	printf("%.0lf\n", avg);
	//중앙값
	printf("%d\n", Vsort[N / 2]);
	//최빈값
	printf("%d\n", Freq);
	//범위
	printf("%d\n", MAX - MIN);
}


#endif 