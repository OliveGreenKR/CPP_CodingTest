#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)

using int64 = long long;


enum
{
	MAX_IN = 10000 +1,
};

inline int Ctoi(char ch) { return ch - '0'; }

string DP[MAX_IN] = { "0","1","1", };
string Sum(string s1, string s2) //s2>s1
{
	::reverse(s1.begin(), s1.end());
	::reverse(s2.begin(), s2.end());

	while (s1.length() != s2.length())
		s1.append("0");

	string tmp;
	tmp.resize(s2.length()+1,'0');

	M_Loop(i, 0, s2.length())
	{	
		int sum = Ctoi(tmp[i]) + Ctoi(s1[i]) + Ctoi(s2[i]);
		tmp[i] = (sum % 10) + '0';
		tmp[i+1] = (sum / 10) + '0';
	}

	if (tmp[tmp.length()-1] == '0')
		tmp = tmp.substr(0, tmp.length() - 1);
	reverse(tmp.begin(), tmp.end());
	return tmp;
}
int main()
{
	FASTIO;

	int N;
	cin >> N;

	M_Loop(i, 3, N + 1)
	{
		DP[i] = Sum(DP[i - 2], DP[i - 1]);
	}

	cout << DP[N] << "\n";
}

#endif 