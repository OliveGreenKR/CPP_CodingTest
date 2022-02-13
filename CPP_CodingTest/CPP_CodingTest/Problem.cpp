#include "pch.h"
#ifdef BACK

#include <iostream>
#include <cstdio>
using namespace std;

//N���� dest�� ����
void PrintHanoi(int N, int start, int dest) {
	int other = 3 - (start + dest) % 3;
	
	if (N < 2)
	{
		printf("%d %d\n", start, dest);
		return;
	}
	else
	{
		PrintHanoi(N - 1, start, other); //N-1���� other��
		printf("%d %d\n", start, dest);	//start->dest
		PrintHanoi(N - 1, other, dest); //N-1���� dest��
	}

}

int main() {
	int N;
	scanf_s("%d", &N);
	printf("%d\n", CntHanoi(N));
	PrintHanoi(N, 1, 3);
}
#endif