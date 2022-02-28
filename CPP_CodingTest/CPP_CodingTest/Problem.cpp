#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,n,st) for(int i=n;i>st;i--)
using int64 = long long;

enum
{
	MAX_IN = 1'000+1
};
string s1;
string s2;

int Ans[MAX_IN][MAX_IN] = {}; //[i][j] '이전'까지의 LCS의 길이

int main()
{
	FASTIO;
	cin >> s1 >> s2; 
	int len1 = s1.length();
	int len2 = s2.length();

	M_Loop(i, 1, len1+1)
	{
		M_Loop(j, 1, len2+1)
		{
			if (s1[i - 1] == s2[j - 1])
				Ans[i][j] = Ans[i - 1][j - 1] + 1;
			else
				Ans[i][j] = ::max(Ans[i - 1][j],Ans[i][j-1]);
		}
	}
	cout << Ans[len1][len2] << "\n";
}

#endif 