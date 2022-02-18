#include "pch.h"
#ifdef BACK

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
enum
{
	_MAX = 8001,
	_HALF = (_MAX) / 2
};
using namespace std;
vector<int> InputCount(_MAX, 0); //Ƚ��
vector<int> Vsort;

int main()
{
	int MAX = INT32_MIN, MIN = INT32_MAX; //�ִ밪 �ּҰ�

	int N;//���Ұ���
	cin >> N;

	int SUM = 0;//�հ�
	int MaxCnt = 0; // �ִ� ȸ��
	for (int i = 0; i < N; i++)
	{
		int input;
		scanf_s("%d", &input);
		SUM += input;
		if (input > MAX)
			MAX = input;
		if (input < MIN)
			MIN = input;
		int cnt = ++InputCount[input + _HALF];
		if (cnt > MaxCnt)
			MaxCnt = cnt;
	}
	//���� ����
	int Freq = INT32_MAX; //�ֺ�
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
	//������
	printf("%.0lf\n", static_cast<double>(SUM) / N);
	//�߾Ӱ�
	printf("%d\n", Vsort[N / 2]);
	//�ֺ�
	printf("%d\n", Freq);
	//����
	printf("%d\n", MAX - MIN);
}
#endif