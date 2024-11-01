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
#include <math.h>
#include <sstream>
#include <cmath>

#define OUT

using namespace std;

string biggerIsGreater(string w) {

    const int n = w.length();

    //check from end
    int i = n - 2;
    while (i >= 0 && w[i] >= w[i + 1])
    {
        --i;
    }

    if (i == -1)
    {
        return "no answer";
    }

    //get the smallest possible char that is the rightest
    int j = n - 1;
    while (w[j] <= w[i])
    {
        j--;
    }

    swap(w[i], w[j]);

    //reverse the substr of right side
    reverse(w.begin() + i + 1, w.end());

    return w;
}
int main() {

}


