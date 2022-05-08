#include "pch.h"
#pragma warning(disable: 4996)
#include <vector>
#include <queue>
#include <algorithm>

#ifdef BACK
#include <iostream>
#include <bitset>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

enum
{
    Max = 1000000,
};
bitset<1000001> bits;
int n, m, x;
int main()
{
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        bits[m] = 1;
    }
    cin >> x;

    int ans = 0;
    for (int i = 1; i < x / 2; i++)
    {
        if (i > Max || x - i > Max) continue;
        else if (bits[i] && bits[x - i]) ans++;
    }
    if ((x % 2 == 1) && bits[x / 2] && bits[x / 2 + 1]) ans++;
    cout << ans;

    return 0;
}



#endif 
