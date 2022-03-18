#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)


#ifdef BACK
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
int64 A, B, C;
int MOD = 0;
vector<int> Table;
void GetAns()
{
}
int main()
{
	FASTIO
	cin >> A >> B >> C;
	
	if (A % C == 0)
	{
		cout << 0;
		return 0;
	}
	Table.resize(B + 1, 1);
	M_Loop(i, 0, B)
		Table[i] = A;

	GetAns();

	cout << MOD;
}
#endif 

