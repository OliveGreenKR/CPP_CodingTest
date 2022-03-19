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
	MAX_IN = 100'000'000'000,
	MAX_N = 5,
	MOD = 1000
};
int64 N, B;
Matrix half;
Matrix nullmat(MAX_N, vector<int64>(MAX_N, 0));
Matrix unitmat(MAX_N, vector<int64>(MAX_N, 0));
Matrix A(MAX_N, vector<int64>(MAX_N, 0));

Matrix Mul(Matrix a, Matrix b)
{ 
	Matrix ret = nullmat;
	M_Loop(k, 0, N)
	{
		M_Loop(j, 0, N)
		{
			M_Loop(i, 0, N)
			{
				ret[k][j] += (a[k][i] * b[i][j])%MOD;
				ret[k][j] %= MOD;
			}
		}
	}
	return ret;
}

Matrix Pow(int64 b)
{
	if (b == 0)
		return unitmat;
	if (b % 2)
		return Mul(A, Pow(b - 1));
	half = Pow(b / 2);
	return Mul(half, half);
}

int main()
{
	FASTIO;


	cin >> N >> B;
	M_Loop(j, 0, N)
	{
		M_Loop(i, 0, N)
			cin >> A[j][i];
	}
	M_Loop(i, 0, N)
	{
		unitmat[i][i] = 1;
	}
	A = Pow(B);
	
	M_Loop(j, 0, N)
	{
		M_Loop(i, 0, N)
			cout << A[j][i] << " ";
		cout << "\n";
	}

	return 0;
}

#endif 
