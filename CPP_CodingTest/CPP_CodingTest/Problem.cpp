#include "pch.h"
#pragma warning(disable: 4996)
#include <vector>
#include <queue>


#ifdef BACK
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
int N, K;
enum
{
    MAX_IN = 100'000+1,
};
int arr[MAX_IN];
int main()
{
    FASTIO;
    cin >> N >> K;
    M_Loop(i, 1, N + 1)
    {
        int tmp; cin >> tmp;
        arr[i] = arr[i - 1] + tmp;
    }
    int max = INT32_MIN;
    M_Loop(i, 1, N-K+2)
    {
        int sum = arr[i + K-1] - arr[i-1];
        max = ::max(max, sum);
    }
    cout << max;
    return 0;
}

#endif 
