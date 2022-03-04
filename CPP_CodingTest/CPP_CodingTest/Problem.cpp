#include "pch.h"
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	MAX_IN = 100
};
int inputs[MAX_IN];
inline int Gcd(int a, int b)// a>b
{
	if (b > a)
		::swap(a, b);
	
	while (b)
	{
		a = a % b;
		::swap(a, b);
	}
	return a;
}
int main()
{
	FASTIO;
	int N;
	cin >> N;
	
	M_Loop(i, 0, N)
		cin >> inputs[i];

	int head = inputs[0];
	M_Loop(i, 1, N)
	{
		int body = inputs[i];
		int gcd = Gcd(head, body);
		cout << head / gcd << "/" << body / gcd << "\n";
	}

}
#endif 
