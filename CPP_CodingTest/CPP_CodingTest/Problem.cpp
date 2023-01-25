#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>`
#include <limits.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


vector<int> stringFailFunction(const string& str) {
    const int size = str.size();
    vector<int> out = vector<int>(size, 0);
    int tail = 0;
    for (int now = 1; now < size; now++) {
        while (tail > 0 && str[now] != str[tail])
            tail = out[tail - 1];

        if (str[tail] == str[now])
            out[now] = ++tail;
    }
    return out;
}


int main() {
	FASTIO;

    string text;
    int L;
    cin >> L >> text;

    auto failfunc = stringFailFunction(text);

    cout << L - failfunc[L-1];
	return 0;
}
#endif 
