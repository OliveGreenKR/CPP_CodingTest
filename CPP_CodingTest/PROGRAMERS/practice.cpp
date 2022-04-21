#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

int main()
{
	int T;
	scanf("%d", &T);

	M_Loop(i, 0, T)
	{
		int N;
		scanf("%d", &N);
		double sum=0;
		int arr[1000];
		M_Loop(i, 0, N)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		sum = sum / N; //now, sum is avg;
		::sort(arr, arr + N);
		printf("%0.3lf%c\n", ((arr + N) - ::find_if(arr, arr + N, [sum](double A) {return A > sum; })) / (double)N * 100,'%');
	}
	return 0;
}