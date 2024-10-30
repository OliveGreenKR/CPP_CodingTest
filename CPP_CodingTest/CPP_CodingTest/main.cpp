#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <deque>

#define OUT

using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {

    //count mods;
    vector<int> mods(k, 0);

    for (const int val : s)
    {
        ++mods[val % k];
    }

    //[mod k ==0] must be added only one.
    int result = ::min(mods[0], 1);

    //compare [i] and [k-i] and choice bigger.
    for (int i = 1; i <= k / 2; ++i)
    {
        int j = k - i;
        if (i == j)
        {
            //if same, must be added only one.
            result += ::min(mods[i], 1);
        }
        else
        {
            result += ::max(mods[i], mods[j]);
        }
    }

    return result;
}

int main() {
    int k = 3;
    vector<int> s = { 1,7,2,4 };

    cout << nonDivisibleSubset(k,s);

    return 0;
}


