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
	MAX_IN = 100'000
};

int N;
//도로길이
//리터당 가격

namespace STR
{
	inline int Ctoi(char ch) { return ch - '0'; }

	string Sum(string s1, string s2) //s1<s2
	{
		::reverse(s1.begin(), s1.end());
		::reverse(s2.begin(), s2.end());

		int len1 = s1.length();
		int len2 = s2.length();

		if (len1 < len2)
		{
			while (s1.length() != s2.length())
				s1.append("0");
		}
		else
		{
			while (s1.length() != s2.length())
				s2.append("0");
		}

		string tmp;
		tmp.resize(s2.length() + 1, '0');

		M_Loop(i, 0, s2.length())
		{
			int sum = Ctoi(tmp[i]) + Ctoi(s1[i]) + Ctoi(s2[i]);
			tmp[i] = (sum % 10) + '0';
			tmp[i + 1] = (sum / 10) + '0';
		}

		if (tmp[tmp.length() - 1] == '0')
			tmp = tmp.substr(0, tmp.length() - 1);
		reverse(tmp.begin(), tmp.end());
		return tmp;
	}
}

string OilPrice[MAX_IN];
string ToGo[MAX_IN];
int main()
{
	FASTIO;
	cin >> N;

	M_Loop(i, 0, N - 1)
		cin >> ToGo[i];
	M_Loop(i, 0, N)
		cin >> OilPrice[i];

	string ANS = "";
	string now = OilPrice[0];//현재선택된 오일가격
	string lenSum = ""; //길이
	M_Loop(i,0,N)
	{
		if (now > OilPrice[i]) //string으로 된 큰 숫자를 숫자로 만드는 함수 필요하다..
		{
			ANS += now * lenSum;
			lenSum = ""; //초기화
			now = OilPrice[i]; //선택
		}
		lenSum += ToGo[i];
	}
}

#endif 