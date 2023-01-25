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


/*

vector<int> makePatternTable(const string& pattern) {

    const int size = pattern.size();
    vector<int> out = vector<int>(size, 0);
    int k = 0;
    for (int i = 1; i < size; i++) {
        while (k > 0 && pattern[i] != pattern[k])
            k = out[k - 1];

        if (pattern[k] == pattern[i])
            out[i] = ++k;
    }
    return out;
}

void kmp(const string& text, const string& pattern) {
    vector<int> ptable = makePatternTable(pattern);

    int j = 0;
    int count = 0;
    vector<int> foundIndex;
    const int last = pattern.size()-1;

    for (int i = 0; i< text.size(); i++) {
        auto& now = text[i];
        while (j >0 && now != pattern[j])
            j = ptable[j-1];

        if (now == pattern[j]) {
            if (j == last) {
                count++;
                int index = (i - last +1);
                foundIndex.push_back(index);
                j = ptable[j];
            }
            else
                j++;
        }
    }

    //��� {count, idx}
    cout << count << "\n";
    for (auto& idx : foundIndex)
        cout << idx << ' ';

    return;
}

*/