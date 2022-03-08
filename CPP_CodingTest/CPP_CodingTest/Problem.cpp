#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 100'000
};

int inputArr[MAX_IN];
int pushArr[MAX_IN];
stack<int> ans;
queue<char> printing;
int main()
{
	FASTIO;

	int N;
	cin >> N;

	M_Loop(i, 0, N)
		cin >> inputArr[i];
	::partial_sort_copy(inputArr, inputArr + N, pushArr, pushArr + N);

	int i = 0;
	M_Loop(j, 0, N)//inputArr
	{
		int& now = inputArr[j];
		for (i; i < N; i++)
		{
			if (!ans.empty())
			{
				if (ans.top() == now)
				{
					printing.push('-');
					ans.pop();
					break;
				}
			}
			printing.push('+');
			ans.push(pushArr[i]);
		}
		if (i >= N)
		{
			if (ans.top() == now)
			{
				printing.push('-');
				ans.pop();
			}
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	while (!printing.empty())
	{
		cout << printing.front() << "\n";
		printing.pop();
	}
	return 0;
}
#endif 
