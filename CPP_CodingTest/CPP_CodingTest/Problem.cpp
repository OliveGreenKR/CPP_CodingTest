#include "pch.h"
#ifdef BACK


#include <cstdio>
using namespace std;


enum
{
	MAX_SLOT = 7
};

int GetNUM(int n)
{	
	int sum = n;
	for (int i = 1; i <= MAX_SLOT; i++)
	{
		int tmp = n % 10;
		sum += tmp;
		n /= 10;
		if (n <= 0)
			break;
	}
	return sum;
}
void GetAns(int N)
{
	int sum;
	for (int i = N/2; i <= N; i++)
	{
		sum = GetNUM(i);
		if (sum == N)
		{
			printf("%d\n", i);
			return;
		}
	}
	printf("%d\n", 0);

}
int main()
{
	
	int N;
	scanf_s("%d", &N);
	GetAns(N);
}

#endif