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
using float64 = long double;

enum
{
	MAX_IN = 50
};
int Sum[MAX_IN] = {0,};  //0 이후로는 다 빼기
string expr;
inline int S_toi(const string& nstr)
{
	if (nstr.empty())
		return 0;

	int ret = 0;
	int tmp = 1;
	M_Loop_sub(i, nstr.length() - 1, -1)
	{
		int n = nstr[i] - '0';
		ret += n * tmp;
		tmp *= 10;
	}
	return ret;
}

int main()
{
	FASTIO;
	cin >> expr;
	expr.append("+");

	int idx = 0;
	int startIt = 0;

	M_Loop(i,0,expr.length())
	{
		char& it = expr[i];
		if (it == '+' || it == '-' || i== expr.length()-1)
		{
			string nstr = expr.substr(startIt, i - startIt);
			startIt = i+1;
			int num = S_toi(nstr);
			Sum[idx] += num;
			if (it == '-')
				idx++;
		}
	}

	int SUM = Sum[0];
	M_Loop(i, 1, MAX_IN)
	{
		if (Sum[i] == 0)
			break;
		SUM -= Sum[i];
	}
	cout << SUM << "\n";
	return 0; 
}

#endif 