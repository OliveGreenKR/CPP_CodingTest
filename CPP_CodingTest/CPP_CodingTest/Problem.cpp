#include "pch.h"
#ifdef BACK

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)

int N;
int Board[15];
int result = 0;

bool IsRight(int i)
{
    M_Loop(j,0,i)
    {
        // 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        if (Board[j] == Board[i] || abs(Board[i] - Board[j]) == (i - j))
            return false;
    }
    return true;
}
void N_Queen(int i)
{
    if (i == N)
        result += 1;
    else
    {
       M_Loop(j,0,N)//열
        {
            Board[i] = j;
            if (IsRight(i))
                N_Queen(i + 1);
        }
    }
}

int main()
{
    cin >> N;

    N_Queen(0);

    cout << result << endl;

    return 0;
}

#endif 