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

void MMul()
{
	M_Loop(k, 0, N)
	{
		M_Loop(j, 0, K)
		{
			M_Loop(i, 0, M)
			{
				C[k][j] += A[k][i] * B[i][j];
			}
		}
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

	MMul();

	M_Loop(j, 0, N)
	{
		M_Loop(i, 0, K)
		{
			cout << C[j][i] << " ";
		}
		cout << "\n";	
	}
	return 0;
}

#endif 
