#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

enum
{
	MAX_IN = 1000
};
int N;
int score[1000];
int main()
{
	FASTIO;
	cin >> N;
	int Max=0;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		score[i]=tmp;
		Max = ::max(Max, tmp);
	}
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (double)score[i]/Max*100;
	}
	cout << sum / N << "\n";
	return 0;
}