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

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5;

std::vector<long long> factorial(MAXN + 1);
std::vector<long long> invFactorial(MAXN + 1);

// Function to calculate x^y % MOD in O(log y)
long long modPow(long long x, long long y, int mod) {
    long long result = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precomputeFactorials() {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    invFactorial[MAXN] = modPow(factorial[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; --i)
    {
        invFactorial[i] = (invFactorial[i + 1] * (i + 1)) % MOD;
    }
}

int answerQuery(const string s, int l, int r) {
    // Return the answer for this query modulo 1000000007.
    // This function is called once before all queries.
    //get modulo the number of 'maximum-length palindromes' in substring(s[l,r])

    //count alphabet
    vector<int> freq(26, 0);

    for (int i = l - 1; i < r; i++)
    {
        freq[s[i] - 'a']++;
    }
    int Odd = 0;
    int possibles = 0;
    //count Odd freq
    for (const int count : freq)
    {
        Odd += count % 2;
        possibles += count / 2;
    }

    //count the number of cases in MAX_LENGTH.
    long long cases;
    cases = factorial[possibles];

    for (const int count : freq)
    {
        if (count / 2 > 1)
        {
            cases = (cases * invFactorial[count / 2]) % MOD;
        }
    }

    if (Odd > 0)
        cases = (cases * Odd) % MOD;

    return cases;
}


int main() {
    precomputeFactorials();
    string s = "cool";
    cout << answerQuery(s, 1, 4);
}
