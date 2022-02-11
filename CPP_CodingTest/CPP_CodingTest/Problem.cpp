#include "pch.h"
#ifdef BACK

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

enum
{
	MAX = 10'000
};

bool cache[MAX+1];

int main()
{
	cache[1] = false;

	for (int i = 2; i < MAX +1; i++)
	{
		cache[i] = true;
	}

	for (int i = 2; i * i <= MAX; i++)
	{
		if (cache[i])
		{
			for (int j = i * 2; j <= MAX; j += i)
				cache[j] = false;
		}
	}

	int T;
	scanf_s("%d", &T);

	while (T>0)
	{
		int n;
		scanf_s("%d", &n);
		
		if (n > MAX || n < 4)
			break;

		int half = n / 2;

		while (true)
		{
			if (cache[half] && cache[n - half])
			{
				printf("%d %d\n", half, n - half);
				break;
			}
			half--;
		}
		T--;
	}

	return 0;
}
#endif