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
int N, M;
enum
{
    MAX_IN = 100'000+1,
};
int arr[MAX_IN]; //0~i ±îÁö ÇÕ.
int main()
{
    FASTIO;
    cin >> N >> M; 
    
    M_Loop(i, 1, N + 1)
    {
        int elm; cin >> elm;
        arr[i] = arr[i-1]+elm;
    }

    M_Loop(k, 0, M)
    {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << "\n";
    }
    return 0;
}

#endif 
