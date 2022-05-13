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
int N, M;
enum
{
    MAX_IN = 1 << 10+1,
};
int Arr[MAX_IN][MAX_IN]; //ºÎºÐÇÕ
int main() {
    FASTIO;
    cin >> N >> M;

    M_Loop(i, 1, N+1)
    {
        M_Loop(j, 1, N + 1)
        {
            cin >> Arr[i][j];
            Arr[i][j] += Arr[i-1][j]+Arr[i][j-1]-Arr[i-1][j-1];
        }
    }
    M_Loop(i, 0, M)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int cnt = 0;
        cnt = Arr[x2][y2] - Arr[x2][y1 - 1] - Arr[x1-1][y2] + Arr[x1-1][y1-1];
        cout << cnt << "\n";
    }
    return 0;
}
#endif 
