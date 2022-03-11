#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
enum
{
	MAX_INPUT = 100
};
queue<pair<int, int>> q;//[중요도][초반위치]
int cache[MAX_INPUT]; //[중요도]

int main()
{
	FASTIO;
	int T;
	cin >> T;

	M_Loop(i, 0, T)
	{
		int N, M;
		//현재 M번째인 원소가 재배열되었을 때 탈출순서
		cin >> N >> M;
		M_Loop(j, 0, N)
		{
			int cost;
			cin >> cost;
			q.push({ cost, j });
			cache[j] = cost;
		}
		::sort(cache, cache + N, ::greater<int>());
		int idx = 0;
		while (idx <= N)
		{
			auto tmp = q.front();
			if (tmp.first == cache[idx])//탈출
			{
				idx++;
				if (q.front().second == M)
				{
					cout << idx << "\n";
					break;
				}
				q.pop();
			}
			else
			{
				q.pop();
				q.push(tmp);
			}
		}
	}
}


#endif 
