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
    MAX_IN = 1'000'000,
    MAX_M = 2'000'000'000
};
vector<int> Arr;
int64 GetCnt(vector<int>& arr, int slice)  //O-n
{
    int64 sum = 0;
    int size = arr.size();
    M_Loop(i, 0, size)
    {
        int64 res = (arr[i] - slice);
        res > 0 ? sum += res : 0;
    }
    return sum;
}
int GetMaxSlice(vector<int>& arr, int M)
{
    int64 mid, left, right;

    left = 0; right = arr[arr.size()-1];
    mid = (right + left) / 2;

    while (left < right)
    {
        mid = (right + left) / 2;
        if (GetCnt(arr, mid) >= M) //자르는 높이를 높여도된다.
            left = mid + 1;
        else
            right = mid;
    }
    if (left == arr[arr.size() - 1]&& GetCnt(arr, left) >= M)
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
