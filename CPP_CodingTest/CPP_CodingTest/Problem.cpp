#include "pch.h"
#pragma warning(disable: 4996)
#include <vector>
#include <queue>


#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
using int64 = long long;
int N, M;
enum 
{
    MAX_IN = 1'000'000+1,
    MAX_M = 1'000
};
int64 Arr[MAX_IN];
int mod[MAX_M];
int main() {
    FASTIO;
    cin >> N >> M;
    M_Loop(i, 1, N + 1) { cin >> Arr[i]; Arr[i] = (Arr[i] + Arr[i - 1]) % M; mod[Arr[i]]++; }

    int cnt = mod[0];

    M_Loop(i, 0, M)
    {
        int tmp = mod[i];
        if (tmp > 1) cnt += tmp * (tmp - 1) / 2;
    } 
    cout << cnt << "\n";
    return 0;
}
#endif 
