#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int i=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int i=(st);i>(M);i--)

priority_queue< int, vector<int>, greater<int>> Bigger; //min Heap
priority_queue< int, vector<int>, less<int>> Smaller; //max Heap
int middle;

int main()
{
	FASTIO;
    int N;
    cin >> N;
    M_Loop(i, 1, N+1)
    {
        int x;
        cin >> x;
        if (i == 1)
        {
            middle = x;
			goto END;
        }
        
        if (x > middle)
            Bigger.push(x);
        else if (x <= middle)
            Smaller.push(x);


        if (i % 2)//odd
		{
			if (Bigger.size() > Smaller.size())
			{
				Smaller.push(middle);
				middle = Bigger.top();
				Bigger.pop();
			}
			else if (Bigger.size() < Smaller.size())
			{
				Bigger.push(middle);
				middle = Smaller.top();
				Smaller.pop();
			}
		}
		else if (Smaller.size() > Bigger.size()) //even
		{
			Bigger.push(middle);
			middle = Smaller.top();
			Smaller.pop();
		}
	END: cout << middle << "\n";
	}
	return 0;
}
#endif 
