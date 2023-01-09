#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define POW(x) (std::pow((x),2))

enum {
	MAX_M = 3'000'000
};

int S = 0;

void HandleCommand(string& cmd, int x) {
	if (cmd ==  "add")
		S |= (1<<x);
	if (cmd == "remove")
		S &= (~(1<<x));
	if (cmd == "check")
		cout << ((S&(1<<x)) ? 1 : 0) << "\n";
	if (cmd == "toggle")
		S ^= (1<<x);
	if (cmd == "all")
		S = (1<<21) -1;
	if (cmd == "empty")
		S = 0;

}

int main() {
	FASTIO;
	int M;

	cin >> M;
	for (int i = 0; i < M; i++) {
		string cmd; int x;
		cin >> cmd;
		if (cmd == "all" || cmd == "empty")
			x = -1;
		else
			cin >> x;
		HandleCommand(cmd, x);
	}

	return 0;
}
#endif 
                      