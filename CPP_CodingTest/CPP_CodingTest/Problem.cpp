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
{
	MAX_IN = 64,
	Color_white = false,//0
	Color_black = true//1
};
int N;
bool Table[MAX_IN][MAX_IN]; 
string ans="";

void DivCon(int nowX,int nowY, int endX, int endY,int cnt=0)
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
				ans += "(";
				DivCon(nowX, nowY, middleX, middleY,1); //1
				DivCon(middleX, nowY, endX, middleY,2); //2
				DivCon(nowX, middleY, middleX, endY,3); //3
				DivCon(middleX, middleY, endX, endY,4); //4
				ans += ")";
				return;
			}
		}
	}
	ans +=::to_string(mark);
}
int main()
{
	FASTIO
		cin >> N;
	
	M_Loop(j, 0, N)
	{
		M_Loop(i, 0, N)
		{
			char c;
			cin >> c;
			Table[j][i] = c - '0';
		}
	}
	DivCon(0, 0, N, N,0);
	cout << ans;
}
#endif 

