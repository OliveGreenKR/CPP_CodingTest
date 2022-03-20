#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
using Matrix = vector<vector<int64>>;
enum : int64
{
	MAT_SIZE = 2,
	MOD = 1'000'000'007
};

Matrix nullmat(MAT_SIZE, vector<int64>(MAT_SIZE, 0));

Matrix A = { {1,1},{1,0} };
Matrix Ans = {{1,0},{0,1}}; //unitmat

Matrix operator*(Matrix&a, Matrix&b)
{
	Matrix ret = nullmat;
	M_Loop(k, 0, MAT_SIZE)
	{
		M_Loop(j, 0, MAT_SIZE)
		{
			M_Loop(i, 0, MAT_SIZE)
			{
				ret[k][j] += (a[k][i] * b[i][j]) % MOD;
				ret[k][j] %= MOD;
			}
		}
	}
	return ret;
}
int main()
{
	FASTIO;

	int64 N;
	cin >> N;

	while (N > 0)
	{
		if (N % 2)
			Ans = Ans * A;
		A = A*A;
		N /= 2;
	}

	cout << Ans[0][1] << "\n";
	return 0;
}

#endif 
