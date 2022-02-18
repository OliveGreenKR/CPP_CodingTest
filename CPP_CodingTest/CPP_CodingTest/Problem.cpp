#include "pch.h"
#ifdef BACK
#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;
#include <stdio.h>

int main(void)
{
	int N, cnt = 0, i = 0, NUM;
	scanf_s("%d", &N);
	while (1)
	{
		if (cnt == N) break;
		if (i % 1000 == 666)
		{
			for (int j = 0; j < 1000; j++)
			{
				NUM = i * 1000 + j;
				cnt++;
				if (cnt == N) break;
			}
			i++;
		}
		else if (i % 100 == 66)
		{
			for (int j = 0; j < 100; j++)
			{
				NUM = i * 1000 + 600 + j;
				cnt++;
				if (cnt == N) break;
			}
			i++;
		}
		else if (i % 10 == 6)
		{
			for (int j = 0; j < 10; j++)
			{
				NUM = i * 1000 + 660 + j;
				cnt++;
				if (cnt == N) break;
			}
			i++;
		}
		else
		{
			NUM = i * 1000 + 666;
			cnt++;
			i++;
		}
	}
	printf("%d", NUM);
	return 0;
}

#endif