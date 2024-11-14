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
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>

#define OUT

using namespace std;

//https://www.hackerrank.com/challenges/short-palindrome/problem?isFullScreen=true
constexpr int MOD = 1000000007;

int shortPalindrome(const std::string& s) {

    std::vector<int> char_count(26, 0);
    std::vector<std::vector<int>> pair_count(26, std::vector<int>(26, 0));  //pair[i][j] = the number of (i,j) pairs
    std::vector<int> triple_count(26, 0);                                   //triple[i] = the number of (i,b,c) tuples when b==c
    long long result = 0;

    // Iterate through the string and update each case.
    for (char ch : s)
    {
        int idx = ch - 'a';

        // current as 'd'
        // result += *(curr,b,c)
        result = (result + triple_count[idx]) % MOD;

        //current as 'c'
        // (a,b,curr) = *(a,b,curr) + *(a,curr)  ,because b==c
        for (int i = 0; i < 26; ++i)
        {
            triple_count[i] = (triple_count[i] + pair_count[i][idx]) % MOD; 
        }

        // current as 'b'
        // (a,curr) = *(a,curr) + *freq(a)  ,because 'a' is selectable regardless of 'b'
        for (int i = 0; i < 26; ++i)
        {
            pair_count[i][idx] = (pair_count[i][idx] + char_count[i]) % MOD;
        }

        // Update the occurrence count 
        char_count[idx] = (char_count[idx] + 1) % MOD;
    }

    return static_cast<int>(result);
}

int main() {

#pragma region OpenFile
    ifstream inputFile("./input.txt"); // �Է� ���� ����
    ofstream outputFile("./output.txt"); // ��� ���� ����
    if (!inputFile)
    {
        cerr << "Unable to open input file";
        return 1; // �Է� ������ �� �� ������ ���α׷� ����
    }
    if (!outputFile)
    {
        cerr << "Unable to open output file";
        return 1; // ��� ������ �� �� ������ ���α׷� ����
    }
#pragma endregion
    //inputFile >> l >> r; // �� �������� l�� r �б�
    
    //do somtehing




    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
#pragma region Close
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}

//int main2()
//{
//}
