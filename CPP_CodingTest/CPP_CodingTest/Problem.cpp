#include "pch.h"
#pragma warning(disable: 4996)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);(i)++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);(i)>(M);(i)--)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
    MAX_IN = 1'000'000,
};
int N;
int arr[MAX_IN];
vector<int> len;
int dp[MAX_IN];  //[i]까지 LIS길이
stack<int> s;

void GetAns(stack<int>& s)
{
	int idx=0;
	len.push_back(arr[0]);
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (len.back() < arr[i])
		{
			len.push_back(arr[i]);
			dp[i] = len.size();
		}
		else
		{
			auto iter = ::lower_bound(len.begin(), len.end(), arr[i]);
			*iter = arr[i];
			dp[i] = iter-len.begin()+1; //교체되는 곳까지의 길이가 LIS의 길이이다.
		}

		if (dp[i] == len.size())
		{
			idx = i;
		}
	}
	
	s.push(arr[idx]);
	for (int i = idx-1; i >= 0; i--)
	{
		if ((arr[i] < arr[idx]) && (dp[i] + 1 == dp[idx]))
		{
			idx = i; s.push(arr[i]);
		}
	}
}

int main()
{
	FASTIO;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	GetAns(s);
	cout << len.size() << "\n";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
#endif 

