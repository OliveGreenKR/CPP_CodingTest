#include "pch.h"
#pragma warning(disable: 4996)
#include <vector>
#include <queue>

#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum 
{
	MAX_N = 100000,
};
int arr[MAX_N]; int X,N;

int FindPair()
{
	int cnt = 0;
	int left = 0, right = N - 1;
	while (left != right)
	{
		int now = arr[left] + arr[right];
		if (now == X) { cnt++; right--; }
		else if (now > X) right--;
		else left++;
	}
	return cnt;
}
int main()
{
	FASTIO;
	cin >> N;
	M_Loop(i, 0, N)
	{
		cin >> arr[i];
	}
	::sort(arr, arr + N);
	cin >> X;

	cout << FindPair() << "\n";
}
#endif 

