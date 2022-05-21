#include "pch.h"
#pragma warning(disable: 4996)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);(i)++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);(i)>(M);(i)--)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using Node = pair<int, int>;
enum
{
    MAX_IN = 1'000'000+1,
};
int N, cnt=0;
int Dp[MAX_IN]; //[최소이동]
int Parent[MAX_IN]; //[부모]
inline int GetN(int n)
{
	return N - n + 1;
}
void Find(int n)
{
	Dp[1] = 0; Parent[1] = 1;
	Dp[2] = 1; Parent[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		Dp[i] = Dp[i - 1] + 1;
		Parent[i] = i - 1;

		if (i % 2 == 0 && Dp[i] >= (Dp[i / 2] + 1))
		{
			Dp[i] = (Dp[i / 2] + 1);
			Parent[i] = i / 2;
		}
		if (i % 3 == 0 && Dp[i] >= (Dp[i / 3] + 1))
		{
			Dp[i] = (Dp[i / 3] + 1);
			Parent[i] = i / 3;
		}
	}
}
int main()
{
	FASTIO;
	cin >> N;
	Find(N);

	cout << Dp[N] << "\n";

	cout << N << " ";
	int idx = N;
	while (idx != 1)
	{
		cout << Parent[idx] << " ";
		idx = Parent[idx];
	}

}
#endif 


