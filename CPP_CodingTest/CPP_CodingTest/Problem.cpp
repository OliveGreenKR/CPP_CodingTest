#include "pch.h"
#ifdef BACK

#include <iostream>
#include <cstdio>
using namespace std;

static int cnt = 0;

void PrintHanoi(int N, int start, int dest) {
	if (N < 1)
		return;

	int other = 3 - ((start + dest) % 3);

	printf("%d %d\n", start, dest);
	
	if (start == 1 && dest == 3)
	{
		PrintHanoi(N - 1, 3,2);
	}
	if (start == 3 && dest == 2)
	{
		PrintHanoi(N, 1, 2);
	}
	if (start == 1 && dest == 2)
	{
		PrintHanoi(N, 1, 3);
	}

	
}

int main() {
	int N;
	scanf_s("%d", &N);
	
	PrintHanoi(N, 1, 3);
	
}
#endif