#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
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
int MAX_CNT = 0;
pair<int, int> Meets[MAX_IN];
int cache[MAX_IN] = {};
int main()
{
	FASTIO;

	cin >> N;

	M_Loop(i, 0, N)
	{
		int f, s;
		cin >> f >> s;
		Meets[i] = pair<int, int>{ f,s };
	}
	
	::sort(Meets, Meets + N, [&](auto& A, auto& B) {
		int left = (A.second - A.first);
		int right = (B.second - B.first);
		if (A.first == B.first)
			return left < right;
		return A.first < B.first;
		 });

	int end = 0;
	int cnt = 0;
	M_Loop(i,0,N)
	{
		cnt = 1;
		const auto& now = Meets[i];

		int& record = cache[i];
		if (record != 0)
		{
			cnt += record;
			continue;
		}
		end = now.second;
		for (auto& meet : Meets)
		{
			if (meet.first < end)
				continue;
			cout << meet.first << "~" << meet.second << "\n";
			cnt++;
			end = meet.second;
		}
		record = cnt;

		cout << "cnt : " << cnt << "\n-----------------------------\n";
		MAX_CNT = ::max(cnt, MAX_CNT);
	}

	cout << MAX_CNT;
}

#endif 