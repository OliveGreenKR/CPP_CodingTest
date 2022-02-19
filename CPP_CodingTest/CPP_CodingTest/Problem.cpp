#include "pch.h"
#ifdef BACK

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define loop(i,n) for(int i=0;i<n;++i)

using namespace std;

const int mxN = 2e4;

string s[mxN];

int main() {
	FASTIO;

	int N; cin >> N;
	loop(i, N) cin >> s[i];

	sort(s, s + N, [&](string& a, string& b){
		return a.length() == b.length() ? a < b : a.length() < b.length();
		});

	N = ::unique(s, s + N) - s;
	loop(i, N)
		cout << s[i] << "\n";
	return 0;
}
#endif