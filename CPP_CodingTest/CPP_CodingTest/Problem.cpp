#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int i=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int i=(st);i>(M);i--)

vector<int> v;
int main()
{
	FASTIO;
    int N;
    cin >> N;
    M_Loop(i, 0, N)
    {
        int x;
        cin >> x;

        if (v.empty() || v.back() < x)
            v.push_back(x);
        else
        {
            auto it = ::lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }

    cout << v.size();
	return 0;
}
#endif 
