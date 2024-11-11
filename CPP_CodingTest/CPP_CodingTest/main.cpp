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

#define OUT

using namespace std;
int getHash(const vector<int>& InVector)
{
    const int MOD = 1e9 + 7;
    int hash = 0;
    for (int i = 0; i < InVector.size(); ++i)
    {
        hash = (hash * 31 + InVector[i]) % MOD;
    }

    return hash;
}

int sherlockAndAnagrams(string s) {
    //get the all number of anamgrams of s's substrings.

    //anagram -> same alphabet frequency
    //accumulation of frequency
    //compare  all substring wiht length [1:n-1]..?

    int n = s.length();
    int result = 0;
    const int MOD = 1e9 + 7;
    //substring's length [1:n]


    for (int len = 1; len < n; len++)
    {

        //substring's frequency 
        vector<int> freq(26);
        for (int i = 0; i < len; i++)
        {
            freq[s[i] - 'a']++;
        }

        //hash table
        unordered_map<int, int> hashFreq;
        int hash = getHash(freq);
        hashFreq[hash]++;

        //sliding window with substring's len
        for (int i = len; i < n; i++)
        {
            freq[s[i - len] - 'a']--;
            freq[s[i] - 'a']++;

            hash = getHash(freq);
            hashFreq[hash]++;
        }

        //compare with all hased freq 
        for (auto it : hashFreq)
        {
            int freq = it.second;
            //combination for count pairs.
            result += freq * (freq - 1) / 2;
        }
    }

    return result;

}


int main() {

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


    //inputFile >> l >> r; // �� �������� l�� r �б�
    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
    
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�

    return 0;
}
