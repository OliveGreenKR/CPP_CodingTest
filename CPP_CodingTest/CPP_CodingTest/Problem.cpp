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
	MAX_IN = 100
};
int A[MAX_IN][MAX_IN], B[MAX_IN][MAX_IN], C[MAX_IN][MAX_IN] = {};
int N, M, K;

void Mul()
{
	int* st_row = A[0];
	int* st_col = B[0];
	int* st_now = C[0];
	int* now = st_now;
	int* row = st_row;
	int* col = st_col;

	M_Loop(k, 0, N)
	{
		M_Loop(j, 0, K)
		{
			M_Loop(i, 0, M)
			{
				(* now) += (*row) * (*col);
				row++;
				col += MAX_IN;
			}
			col = ++st_col;
			row = st_row;
			now++;
		}
		st_row += MAX_IN;
		st_now += MAX_IN;
		now = st_now;
		row = st_row;
		st_col = B[0];
		col = st_col;
	}
	
	
}
int main()
{
	FASTIO;
	cin >> N >> M;
	M_Loop(j, 0, N) 
	{
		M_Loop(i, 0, M)
			cin >> A[j][i];
	}
		
	cin >> M >> K;
	M_Loop(j, 0, M)
	{
		M_Loop(i, 0, K)
			cin >> B[j][i];
	}

	Mul();

	return 0;
}

#endif 
