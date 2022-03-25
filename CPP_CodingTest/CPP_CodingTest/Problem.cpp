#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int i=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int i=(st);i>(M);i--)
using int64 = long long;

enum
{
    BIG =0,
    SMALL =1,
};
vector<int> Arr;
int GetCnt(vector<int>& arr, int slice, int count)  //O-n
{
    bool ret = false;
    int size = arr.size();
    int64 cnt = 0, len = 0, dist = 0;
    M_Loop(i, 0, size-1)
	{
		dist = arr[i + 1] - arr[i];
		len += dist;

		if (len >= slice)
		{
			cnt > 0 ? cnt++ : cnt += 2;
			len = 0;
		}
        if(cnt  >= count)
           return SMALL;
	}
    return BIG;
}
int GetMaxSlice(vector<int>& arr, int M)
{
    int64 mid, left, right;

    left = 1; right = (arr[arr.size()-1]-arr[0]+1);
    mid = (right + left) / 2;
    int state = SMALL;
    while (left < right)
    {
        mid = (right + left) / 2;
        state = GetCnt(arr, mid, M);
        if (state ==  SMALL) //자르는 높이를 높여도된다.
            left = mid + 1;
        else
            right = mid;
    }
    if (left == (arr[arr.size() - 1] - arr[0] + 1) / M && GetCnt(arr, left, M) == SMALL)
        left++;
    return left-1;
}

int main()
{
	FASTIO;
    int M, N;
    cin >> N >> M;
    Arr.resize(N, 0);
    M_Loop(i, 0, N)
        cin >> Arr[i];
    ::sort(Arr.begin(), Arr.end());

    cout << GetMaxSlice(Arr, M);
	return 0;
}
#endif 
