#include "pch.h"
#ifdef BACK
#include <iostream>
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
int Stack[MAX_IN+1];
int idx = 0; 
int val = 0; //push가능한 최소수
queue<char> printing;

int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 0, N)
	{
		int input; 
		cin >> input;
		if (val <= input)//push 가능
		{
			while (val < input)
			{
				idx++;
				val++;
				printing.push('+');
				Stack[idx] = val;
			}
			printing.push('-');
			idx--;
		}
		else//push 불가능
		{
			if (Stack[idx] == input)
			{
				printing.push('-');
				idx--;
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
