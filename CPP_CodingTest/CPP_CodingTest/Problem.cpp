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
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_IN = 1'000+1
};
string s1;
string s2;
int Dp[MAX_IN][MAX_IN] = {}; //[i][j]까지의 LCS의 길이

int LCS(string& s1, string& s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	for (int i = 1; i<=len1; i++)
	{
		for (int j = 1; j<=len2; j++)
		{
			if (s1[i-1]==s2[j-1])
			{
				Dp[i][j] = Dp[i-1][j-1]+1;
			}
			else
				Dp[i][j] = ::max(Dp[i-1][j], Dp[i][j-1]);
		}
	}

	return Dp[len1][len2];
}

void Track(string& s1, string& s2)
{
	cout<<LCS(s1, s2)<<"\n";
	int i = s1.length(), j = s2.length();
	int idx; stack<char> s;
	while (Dp[i][j]!=0)
	{
		if (Dp[i-1][j]==Dp[i][j]) i--;
		else if (Dp[i][j-1]==Dp[i][j]) j--;
		else
		{
			s.push(s1[i-1]);
			i--; j--;
		}
	}
	while (!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}

int main()
{
	FASTIO;
	cin>>s1>>s2;
	int len1 = s1.length();
	int len2 = s2.length();

	int idx = 0; // 현재 LCS끝 idx
	stack<int> s;

	Track(s1, s2);
	return 0;
}
#endif 

