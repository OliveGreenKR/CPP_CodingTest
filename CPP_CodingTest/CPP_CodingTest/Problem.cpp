#include "pch.h"
#ifdef BACK

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,n) for(int i=0;i<n;++i)

using namespace std;

const int MAX_IN = 1'000'000;

int Input[MAX_IN] = { 0, };
int Input_Unique[MAX_IN] = { 0, };

int main() {
	FASTIO;

	int N;
	cin >> N;

	M_Loop(i, N) 
	{
		cin >> Input[i];
		Input_Unique[i]= Input[i];
	}
	::sort(Input_Unique, Input_Unique + N);
	::unique(Input_Unique, Input_Unique + N);
	M_Loop(i, N)
	{
		auto findit = ::find(Input_Unique, Input_Unique + N, Input[i]);
		cout << findit - Input_Unique << " ";
	}

}
#endif 