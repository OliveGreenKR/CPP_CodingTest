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
