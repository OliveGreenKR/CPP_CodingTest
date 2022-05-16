#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
    MAX_IN = 100'000+1,
};
int N, S;
int arr[MAX_IN];
int main() 
{
    FASTIO;
    cin >> N >> S;
    M_Loop(i, 1, N+1)
    {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    if (arr[N] < S) { cout << 0 << "\n"; return 0; }

    int left = 1, right = 1, len = MAX_IN;
    while (left <= N && right<= N )
    {
        int sum = arr[right]-arr[left - 1];
        if (sum < S) right++;
        else
        {
            len = ::min(len, right - left + 1);
            if (left < right)
                left++;
            else right++;
        }
    }
    cout << len << "\n";
    return 0;
}
#endif 
