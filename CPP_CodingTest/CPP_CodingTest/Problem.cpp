#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,K) for(int i=(st);i<(K);i++)
#define M_Loop_sub(i,st,K) for(int i=(st);i>(K);i--)
using int64 = long long;
vector<int> Arr;
int64 GetCnt(vector<int>& arr, int slice)  //O-n
{
    int64 sum = 0;
    int size = arr.size();
    M_Loop(i, 0, size)
    {
        sum += arr[i] / slice;
    }

    return sum;
}
int GetMaxSlice(vector<int>& arr, int N)
{
    int64 mid, left, right;

    left = 1; right = arr[arr.size()-1];
    mid = (right + left) / 2;

    while (left < right)
    {
        mid = (right + left) / 2;
        if (GetCnt(arr, mid) >= N) //ÃÖ´ë
            left = mid + 1;
        else
            right = mid;
    }
    if (left == arr[arr.size() - 1]&& GetCnt(arr, left) >= N)
        left++;
    return left-1;
}

int main()
{
	FASTIO;
    int K,N;
    cin >> K >> N;
    Arr.resize(K, 0);
    M_Loop(i, 0, K)
        cin >> Arr[i];
    ::sort(Arr.begin(), Arr.end());

    cout << GetMaxSlice(Arr, N);
	return 0;
}
#endif 
