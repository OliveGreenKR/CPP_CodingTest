#include "pch.h"
#ifdef BACK

#include <vector>
#include <list>
#include <algorithm>
#include<string>

#include <iostream>
using namespace std;

/* 정수 N소인수 분해하기. */

bool IsPrime(const int& N)
{
	if (N <= 1)
		return false;

	for (int i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
    int N;
    cin >> N;
    
    if (N <= 1)
        return 0;

    int i = 2;

    while (i*i <= N)
    {
        if (N % i == 0)
        {
            cout << i << endl;
            N /= i;
        }
        else i++;
    }
    cout << N << endl;
}
#endif