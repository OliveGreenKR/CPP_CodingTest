#include "pch.h"
#ifdef BACK
#include <iostream>
#include <cstdio>
#include<vector>
#include <string>
using namespace std;

enum
{
	WHITE = 0,
	BLACK = 1
};

int Check(const vector<vector<int>>&arr, int y, int x)
{
	int ret=0;

	int CorrectColor = arr[y][x];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i+y][j+x] ^ CorrectColor)
				ret++;
			CorrectColor = CorrectColor ^ 1;
		} 
		CorrectColor = CorrectColor ^ 1;
	}
	return ret;
}


int Check2(const vector<vector<int>>& arr, int y, int x)
{
	int ret = 0;

	int CorrectColor = arr[y][x];
	CorrectColor = CorrectColor ^ 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i + y][j + x] ^ CorrectColor)
				ret++;
			CorrectColor = CorrectColor ^ 1;
		}
		CorrectColor = CorrectColor ^ 1;
	}
	return ret;
}

int main()
{
	int M, N;
	scanf_s("%d%d", &N, &M);
	vector<vector<int>> arr(N,vector<int>(M,-1));

	for (int j = 0; j < N; j++)
	{
		string str;
		cin >> str;
		for (int i = 0 ;  i < M ; i++)
		{
			char c = str[i];
			if (c == 'W')
				arr[j][i] = WHITE;
			if (c == 'B')
				arr[j][i] = BLACK;
		}
	}
	
	int cangoRight = M - 8;
	int cangoDown = N - 8;
	int ret = INT32_MAX;

	for (int i = 0; i <= cangoDown;i++)
	{
		for (int j = 0; j <= cangoRight; j++)
		{
			int cnt = min(Check(arr, i, j), Check2(arr, i, j));
			if (ret > cnt)
			{
				ret = cnt;
				if (ret == 0)
				{
					printf("%d\n", ret);
					return 0;
				}
			}
				
		}
	}
	printf("%d\n", ret);
}

#endif