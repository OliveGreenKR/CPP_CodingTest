#include "pch.h"
#ifdef BACK

#include <cstdio>
using namespace std;

int main()
{
	int N;
	scanf_s("%d", &N);

	//비트반전
	int comple = (N ^ -1) + 1 ;

	int cnt = 0;
	for (int i = 0; i < 32; i++)
	{
		int mask = 1 << i;
		if( (N &mask) ==  (comple&mask))
			continue;
		cnt++;
	}
	printf("%d", cnt);
}

#endif