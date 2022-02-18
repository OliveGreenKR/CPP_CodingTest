#include "pch.h"
#ifdef BACK
#include <iostream>

using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>


//최대숫자 범위는 1~ 10'000
enum
{
	MAX = 10'001
};

int cSum[MAX];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int index = 0;
		scanf("%d", &index);
		cSum[index]++;
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < cSum[i]; j++)
			printf("%d\n", i);
	}
	return 0;
}


#endif