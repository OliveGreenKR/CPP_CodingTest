#include "pch.h"
#ifdef BACK

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#include <algorithm>
#include <string>
#include <queue>

int main()
{
	priority_queue<int, vector<int>, less<int>> ans;
	string str;
	cin >> str;
	for (char c : str)
	{
		ans.emplace(static_cast<int>(c - '0'));
	}
	while (!ans.empty())
	{
		printf("%d", ans.top());
		ans.pop();
	}
	printf("\n");
}
#endif