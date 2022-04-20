#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

//o=79 x = 88
enum
{
	MAX_IN = 80,
};
int score[MAX_IN];

int main()
{
	FASTIO;
	int T;
	cin >> T;

	M_Loop(i, 0, T)
	{
		string str;
		cin >> str;
		int sum = 0;
		int partsum = 0;
		for (char c : str)
		{
			if (c == 'O')
				partsum++;
			else
				partsum = 0;
			sum += partsum;
		}
		cout << sum << "\n";
	}
	return 0;
}