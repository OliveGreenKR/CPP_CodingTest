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
int N;
int arr[MAX_IN];
int main() 
{
    FASTIO;
    ::memset(arr, -1, sizeof(arr));
    vector<long long> sumarr = { 0 };
    cin >> N;
    for (int i = 2; i < MAX_IN; i++)
    {
        if (arr[i] == -1)
        {
            for (int j = 2; i * j < MAX_IN; j++)
            {
                arr[i * j] = 0;//¼Ò¼ö¾Æ´Ô
            }
            sumarr.push_back(i+sumarr[sumarr.size()-1]);
        }
    }

    int cnt = 0; int left=1,right = 1;

    while (left <= right && right < sumarr.size())
    {
        int ck = sumarr[right] - sumarr[left - 1];
       
        if (ck <= N) 
        {
            if (ck == N) cnt++;
            right++; 
        }
        else
        {
           left++;
        }
        
    }
    cout << cnt << "\n";
    return 0;
}
#endif 
