#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

int main()
{
	FASTIO;
	int T; cin >> T;
	M_Loop(i, 0, T)
	{
		int A, B;
		cin >> A >> B;
		cout << A + B << "\n";
	}
}