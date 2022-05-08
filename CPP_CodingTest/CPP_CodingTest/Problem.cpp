#include "pch.h"
#pragma warning(disable: 4996)
#include <vector>
#include <queue>

#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
enum 
{
	MAX_N = 100000,
};
int arr[MAX_N]; int X,N;

int FindPair()
{
	int cnt = 0;
	int left = 0, right = N - 1;
	while (left != right)
	{
		int now = arr[left] + arr[right];
		if (now == X) { cnt++; right--; }
		else if (now > X) right--;
		else left++;
	}
	return cnt;
}
int main()
{
	FASTIO;
	cin >> N;
	M_Loop(i, 0, N)
	{
		cin >> arr[i];
	}
	::sort(arr, arr + N);
	cin >> X;

	cout << FindPair() << "\n";
}
#endif 

#include <iostream>
#include <bitset>
using namespace std;
const int Max = 1000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bitset<1000001> a;
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        a[m] = 1;
    }
    cin >> x;

    int ans = 0;
    for (int i = 1; i < x / 2; i++)
    {
        if (i > Max || x - i > Max) continue;
        else if (a[i] && a[x - i]) ans++;
    }
    if ((x % 2 == 1) && a[x / 2] && a[x / 2 + 1]) ans++;
    cout << ans;
}