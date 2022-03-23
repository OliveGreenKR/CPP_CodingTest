#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
vector<int> Arr;

int get_lower(vector<int>& arr, int m) 
{
    int mid, start, end;
    start = 0, end = arr.size()-1;

    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] >= m)//
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int get_upper(vector<int>& arr, int m) 
{
    int mid, start, end;
    start = 0, end = arr.size() - 1;

    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] > m)//
            end = mid;
        else start = mid + 1; ////
    }
    return end;
}
int main()
{
	FASTIO;
    int N;
    cin >> N;
    Arr.resize(N, 0);
    M_Loop(i, 0, N)
        cin >> Arr[i];

    ::sort(Arr.begin(), Arr.end());

    int M;
    cin >> M;
    M_Loop(i, 0, M)
    {
        int m;
        cin >> m;

        //못찾으면 둘은 같은 값을 반환한다.
        int lower = get_lower(Arr, m);
        int upper = get_upper(Arr, m);
        if (upper == Arr.size() - 1 && Arr[upper] == m)
            upper++;
        cout << upper - lower << " ";
    }
    
	return 0;
}
#endif 
