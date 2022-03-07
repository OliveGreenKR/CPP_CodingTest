#include "pch.h"
#ifdef BACK
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 100+1
};

int main()
{
	FASTIO;
	while (true)
	{
		string test;
		getline(cin, test);
		if (test == ".")
			break;

		stack<char> brackets;
		for (char c : test)
		{
			if (c == '(' || c == '[')
				brackets.push(c);
			else if (c == ')')
			{
				if (brackets.empty())
				{
					brackets.push(c);
					break;
				}
					
				if (brackets.top() == '(')
					brackets.pop();
				else
				{
					brackets.push(c);
					break;
				}
			}
			else if (c == ']')
			{
				if (brackets.empty())
				{
					brackets.push(c);
					break;
				}
				if (brackets.top() == '[')
					brackets.pop();
				else
				{
					brackets.push(c);
					break;
				}
			}
		}
		if (brackets.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
#endif 
