#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <map>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
map<int, int> Card;
int main()
{
	FASTIO;

	int N;
	cin >> N;

	M_Loop(i, 0, N)
	{
		int n;
		cin >> n;
		if (Card.find(n) != Card.end())
			Card.at(n)++;
		else
			Card.emplace(n, 1);
	}

	int M;
	cin >> M;

	M_Loop(i, 0, M)
	{
		int m;
		cin >> m;
		if (Card.find(m) != Card.end())
			cout << Card.at(m) << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}
#endif 
