#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)


inline void swap(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;

}

void permute(char* a, int l, int r)
{
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a + l, a + i);
			permute(a, l + 1, r);
			swap(a + l, a + i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	char str[] = "ABC";
	permute(str, 0, 2);
	return 0;
}