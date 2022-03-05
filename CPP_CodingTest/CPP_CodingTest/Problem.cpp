#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 30+1
};
map<string, int> ClothMAP[MAX_IN];
int64 ANS[MAX_IN];
int main()
{
	FASTIO;
	int T;

	cin >> T;
	M_Loop(i, 0, T)
	{
		int N;
		cin >> N;
		M_Loop(j,0,N)
		{
			string tmp, cloth;
			cin >> tmp >> cloth;
			if (ClothMAP[i].find(cloth) != ClothMAP[i].end())
				ClothMAP[i][cloth]++;
			else
				ClothMAP[i].emplace(cloth, 1);
		}
	}
	M_Loop(i, 0, T)//테스트케이스
	{	
		int64& ans = ANS[i];
		ans = 1;
		for (auto clth : ClothMAP[i])
		{
			int& res = clth.second;
			if (res == 0)
				break;
			ans *= (res + 1);
		}
		ans -= 1;//알몸인경우 제외
		cout << ans << "\n";
	}
}
#endif 
