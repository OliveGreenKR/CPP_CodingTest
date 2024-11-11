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

int steadyGene(string gene) {

    //the steady number of  'ACTG' is depending on str's length.
    int n = gene.size();
    int requiredCount = n / 4;
    unordered_map<char, int> freq;
    int excessCount = 0;

    //make frequency 
    for (char c : gene)
    {
        freq[c]++;
        if (freq[c] > requiredCount)
        {
            excessCount++;
        }
    }

    //already steady
    if (excessCount == 0)
    {
        return 0;
    }

    //sliding window
    int left = 0, right = 0;
    int MIN = n;
    while (right < n)
    {
        //moving right
        if (freq[gene[right]] > requiredCount)
        {
            excessCount--;
        }
        freq[gene[right]]--;

        //find the most left-index
        while (excessCount == 0 && left <= right)
        {
            MIN = min(MIN, right - left + 1);
            freq[gene[left]]++;
            if (freq[gene[left]] > requiredCount)
            {
                excessCount++;
            }

            left++;
        }

        right++;
    }

    return MIN;
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
