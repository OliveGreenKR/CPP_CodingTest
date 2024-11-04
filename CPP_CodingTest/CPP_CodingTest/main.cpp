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

vector<int> absolutePermutation(int n, int k) {
    // If k is 0, return the natural order [1, 2, 3, ..., n]
    if (k == 0)
    {
        vector<int> result(n);
        for (int i = 0; i < n; ++i)
        {
            result[i] = i + 1;
        }
        return result;
    }

    // If n is not divisible by 2 * k, return -1 (impossible case)
    if (n % (2 * k) != 0)
    {
        return { -1 };
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
    {
        // Determine if we are in the first half of the 2k block or the second half
        if ((i / k) % 2 == 0)
        {
            result[i] = i + 1 + k; // Place element k positions ahead
        }
        else
        {
            result[i] = i + 1 - k; // Place element k positions behind
        }
    }

    return result;
}

int main() {

}


