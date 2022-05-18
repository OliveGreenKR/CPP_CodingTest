#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum
{
    MAX_IN = 4'000'000+1
};
#include <cstdio>
bool p[MAX_IN];
int prime[290000];
int N;
int main() {
    FASTIO;
    cin >> N;
    //N까지 소수 아닌거 구하기
    for (int i = 3; i * i <= N; i += 2)
        if (!p[i])
            for (int j = i * i; j <= N; j += i + i)
                p[j] = true;
    int pdx=0, cnt=0, left=0, right=0, sum=0;
    prime[pdx++] = 2;
    for (int i = 3; i <= N; i += 2) if (!p[i]) prime[pdx++] = i;
    while (right < pdx) {
        if (sum < N) {
            sum += prime[right++];
            if (sum == N) {
                cnt++;
                sum -= prime[left++];
            }
        }
        if (sum > N) {
            sum -= prime[left++];
            if (sum == N) {
                cnt++;
                sum -= prime[left++];
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
#endif 


