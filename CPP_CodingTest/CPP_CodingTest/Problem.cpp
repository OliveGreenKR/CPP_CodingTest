#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)


#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

using namespace std;
int N;
int Table[3000][3000];
int Ans[3] = {};

bool check(int nowX, int nowY, int size) { // 전부 같은 색깔인지 검사
    int mark = Table[nowY][nowX];
    M_Loop(j,nowY,nowY+size) {
        M_Loop(i,nowX,nowX+size) {
            if (mark != Table[j][i]) 
                return false;
        }
    }
    return true;
}

void DivC(int nowX, int nowY, int len) {
   
    if (check(nowX, nowY, len)) 
    {
        Ans[Table[nowY][nowX]]++;
        return;
    }

   int div_len = len / 3; 
   if (div_len)
   {
       M_Loop(j, 0, 3)
       {
           M_Loop(i, 0, 3)
               DivC(nowX + i*div_len, nowY + j*div_len, div_len);
       }
   }
}

int main(void) {
    FASTIO
    cin >> N;
    M_Loop(i,0,N)
    {
        M_Loop(j, 0, N)
        {
            cin >> Table[i][j]; 
            Table[i][j]++; // 0, 1, 2 로 변환
        }      
    }
    DivC(0, 0, N);

    for (auto c : Ans) {
        cout << c << '\n';
    }
}
#endif 

