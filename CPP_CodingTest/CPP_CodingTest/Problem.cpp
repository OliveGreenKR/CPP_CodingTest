#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,n) for(int i=0;i<n;++i)

using namespace std;
vector<pair<int, int>> Input; //{ val, 입력순서}
int main() {
	FASTIO;
	int N;
	cin >> N;
	M_Loop(i, N)
	{
		int in;
		cin >> in;
		Input.push_back(pair<int,int>{ in,i });
	}
	vector<int> ans(N);

	::sort(Input.begin(),Input.end());

	int comp = 0, prev_val = Input[0].first;
	for (auto& pair : Input)
	{
		int now_val = pair.first;
		int idx = pair.second;
		if (prev_val != now_val) ++comp;
		prev_val = now_val;
		ans[idx] = comp;
	}
	for (int c : ans)
		cout << c << " ";
}
#endif 