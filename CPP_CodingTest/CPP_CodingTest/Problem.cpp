#include "pch.h"
#ifdef BACK
#include <vector>
#include <list>
#include <algorithm>
#include<string>
#include <iostream>
using namespace std;

void Add(const string& str, vector<int>& ans)
{
	int current = 0;

	for (char c : str)
	{
		int& here = ans[current];
		if (here == -1)
			here = 0;

		ans[current] += c - '0';
		current++;
	}
}

void Answering(vector<int>& ans)
{

	for (int i= 0; i < ans.size() ; i ++)
	{
		int& now = ans[i];

		if (now > 9)
		{
			int& next = ans[i + 1];
			next == -1 ? next = now / 10 : next += now / 10;
			now = now % 10;
		}

	}
}

int main()
{
	string A, B;
	cin >> A >> B;
	
	vector<int> ans(7,-1);
	
	::reverse(A.begin(), A.end());
	::reverse(B.begin(), B.end());

	Add(A, ans);
	Add(B, ans);

	Answering(ans);

	for (int i = ans.size()-1; i >= 0; --i)
	{
		const int& c = ans[i];
		if(c!=-1)
			cout << c;
	}

	return 0;
}
#endif