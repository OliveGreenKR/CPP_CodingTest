#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

enum
{
	MOD = 42
};
set<int> ans;
int main()
{
	FASTIO;
	for (int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		ans.emplace(x % MOD);
	}
	cout << ans.size() << "\n";
}