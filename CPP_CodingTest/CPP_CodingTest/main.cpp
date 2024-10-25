#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define OUT

constexpr const int MOD = (1e9 + 7);

// Function to calculate the number of ways to build one row of width m
long long countWaysToBuildRow(int width, std::vector<long long>& memo) {

    //Base State
    if (width == 0) return 1;
    if (width < 0) return 0;

    // Return the stored result if already calculated
    if (memo[width] != -1)
        return memo[width];

    // Recursive case: try placing bricks of width 1, 2, 3, or 4
    long long ways = countWaysToBuildRow(width - 1, memo) % MOD +
        countWaysToBuildRow(width - 2, memo) % MOD +
        countWaysToBuildRow(width - 3, memo) % MOD +
        countWaysToBuildRow(width - 4, memo) % MOD;
    ways %= MOD;

    // Store Results
    memo[width] = ways;
    return ways;
}

int modExp(long long base, int exp, int mod) {
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int legoBlocks(int n, int m) {

    vector<long long> OneRow(m + 1, -1);
    countWaysToBuildRow(m, OneRow);

    vector<long long> NRows(m + 1, 0);

    //Count all ways in height 'n'
    for (int i = 1; i <= m; i++)
    {
        NRows[i] = modExp(OneRow[i], n, MOD);
    }

    //Selection Valid Wall
    vector<long long> validWalls(m + 1, 0);
    validWalls[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        validWalls[i] = NRows[i];
        for (int j = 1; j < i; j++)
        {
            validWalls[i] = (validWalls[i] - (validWalls[j] * NRows[i - j]) % MOD + MOD) % MOD;
        }
    }

    return validWalls[m];

}
int main() {

    cout << legoBlocks(2, 2) << endl;
    cout << legoBlocks(3, 2) << endl;
    cout << legoBlocks(4, 4) << endl;

 
}