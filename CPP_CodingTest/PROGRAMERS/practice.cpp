#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

struct Heap;
struct Heap
{
	int size;
	int container[1000000];
};
void FindLessthan(int x, Heap* h, int now=1)
{
	if (now > h->size || h->container[now] >= x)
	{
		return;
	}
	cout << h->container[now] << " ";
	FindLessthan(x, h, now * 2);
	FindLessthan(x, h, now * 2 + 1);
}


Heap MakeUnion(Heap* lhs, Heap* rhs)
{

}
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