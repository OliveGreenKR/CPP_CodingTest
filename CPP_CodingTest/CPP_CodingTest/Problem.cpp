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

const int MAX_IN = 100'000;
pair<int, string*> ans[MAX_IN]; 
string ids[MAX_IN];
int main() {
	FASTIO;
	int N; cin >> N;
	M_Loop(i, N)
	{
		int age;
		string id;
		cin >> age >> id;
		ids[i] = id;
		ans[i] = make_pair(age, &ids[i]);
	}
	::sort(ans, ans + N);
	M_Loop(i, N)
		cout << ans[i].first << " " << *(ans[i].second) << "\n";
}
#endif