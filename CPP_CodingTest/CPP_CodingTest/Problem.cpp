#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)


#ifdef BACK
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

enum
{ MAX_IN = 2187,}; //3^7

enum State
{
	High	= 1,
	Middle	= 0,
	Low		= -1
};

int N;
bool Table[MAX_IN][MAX_IN]; 
int Ans[3] = {};

void DivCon(int nowX,int nowY, int endX, int endY,int row=0)
{
	int middleX1 = (nowX + endX) / 3;
	int middleX2 = (nowX + endX) / 3 * 2;

	int middleY1 = (nowY + endY) / 3;
	int middleY2 = (nowY + endY) / 3 * 2;

	bool mark = Table[nowY][nowX];

	M_Loop(j, nowY, endY)
	{
		M_Loop(i, nowX, endX)
		{
			if (mark != Table[j][i])
			{

				DivCon(nowX, nowY, middleX1, middleY1);			//1
				DivCon(middleX1,nowY,middleX2,middleY1);		//2
				DivCon(middleX2, nowY, endX, middleY1);			//3

				DivCon(nowX, middleY1, middleX1, middleY2);		//4
				DivCon(middleX1, middleY1, middleX2, middleY2);	//5
				DivCon(middleX2, middleY1, endX, middleY2);		//6

				DivCon(nowX, middleY2, middleX1, endY);			//7
				DivCon(middleX1, middleY2, middleX2, endY);		//8
				DivCon(middleX2, middleY2, endX, endY);			//9

				return;
			}
		}
	}
	switch(mark)
	{
	case State::High:
		Ans[2]++; break;
	case State::Middle:
		Ans[1]++; break;
	case State::Low:
		Ans[0]++; break;
	}
}
int main()
{
	FASTIO
		cin >> N;
	
	M_Loop(j, 0, N)
	{
		M_Loop(i, 0, N)
		{
			cin >> Table[j][i];
		}
	}
	DivCon(0, 0, N, N);
}
#endif 

