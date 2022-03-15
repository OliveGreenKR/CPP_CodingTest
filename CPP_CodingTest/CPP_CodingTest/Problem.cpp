#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

enum
{
	MAX_IN = 128,
	Color_white = false,
	Color_blue = true
};
int N;
bool Table[MAX_IN][MAX_IN]; 

int White = 0;
int Blue = 0;

void DivCon(int nowX,int nowY, int endX, int endY)
{
	int middleX = (nowX + endX) / 2;
	int middleY = (nowY + endY) / 2;
	bool mark = Table[nowY][nowX];

	M_Loop(j,nowY,endY)
	{
		M_Loop(i,nowX,endX)
		{
			if (mark != Table[j][i])
			{
				DivCon(nowX, nowY, middleX, middleY); //1
				DivCon(middleX, nowY, endX, middleY); //2
				DivCon(nowX, middleY, middleX, endY); //3
				DivCon(middleX, middleY, endX, endY); //4
				return;
			}
		}
	}
	mark == Color_white ? White++ : Blue++;
}
int main()
{
	FASTIO
	cin >> N;
	M_Loop(j, 0, N)
	{
		M_Loop(i, 0, N)
			cin >> Table[j][i];
	}

	DivCon(0, 0, N, N);
	cout << White << "\n" << Blue << "\n";
}
#endif 

