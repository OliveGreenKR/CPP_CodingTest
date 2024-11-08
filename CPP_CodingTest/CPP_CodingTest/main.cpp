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
#include <fstream> // 파일 입출력을 위한 헤더 추가

#define OUT

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5;

std::vector<long long> factorial(MAXN + 1);
std::vector<long long> invFactorial(MAXN + 1);
vector<vector<int>> prefixFreq(MAXN+1,vector<int>(26,0));

// Function to initialize prefix frequency array
void initializePrefixFreq(const string& s) {
    int n = s.size();
    
    for (int i = 1; i <= n; ++i)
    {
        prefixFreq[i] = prefixFreq[i - 1];
        prefixFreq[i][s[i-1] - 'a']++;
    }
}

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


void initialize(string s) {
    // This function is called once before all queries.
    precomputeFactorials();
    initializePrefixFreq(s);
}

int answerQuery(int l, int r)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < 26; ++i)
    {
        freq[i] = prefixFreq[r][i] - prefixFreq[l - 1][i];
    }

    int Odd = 0;
    int halfPairs = 0;

    //count odd and pairs
    for (const int count : freq)
    {
        Odd += count % 2;
        halfPairs += count / 2;
    }

    //count the number of cases in MAX_LENGTH.
    long long cases;
    cases = factorial[halfPairs];

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

    ifstream inputFile("./input.txt"); // 입력 파일 열기
    ofstream outputFile("./output.txt"); // 출력 파일 열기
    if (!inputFile)
    {
        cerr << "Unable to open input file";
        return 1; // 입력 파일을 열 수 없으면 프로그램 종료
    }
    if (!outputFile)
    {
        cerr << "Unable to open output file";
        return 1; // 출력 파일을 열 수 없으면 프로그램 종료
    }


    //inputFile >> l >> r; // 각 쿼리에서 l과 r 읽기
    //outputFile << result << "\n"; // 결과를 출력 파일에 쓰기
    
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기

    return 0;
}
