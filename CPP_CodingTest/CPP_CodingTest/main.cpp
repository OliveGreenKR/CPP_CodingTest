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
#include <bitset>

#define OUT

using namespace std;

int pairs(int k, vector<int> arr) {
    unordered_set<int> elementSet;

    for (const int elm : arr)
    {
        elementSet.insert(elm);
    }

    int countPairs = 0;
    for (const int e : arr)
    {
        if (elementSet.find(e - k) != elementSet.end())
        {
            countPairs++;
        }
        if (elementSet.find(e + k) != elementSet.end())
        {
            countPairs++;
        }
        elementSet.erase(e);
    }

    return countPairs;
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
    int k = 2;
    vector<int> pair = { 1,5,3,4,2 };
    cout << pairs(2, pair);

    //outputFile << result << "\n"; // 결과를 출력 파일에 쓰기
    
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
    

    //8,705,701,581,298,678
    return 0;
}

//int main2()
//{
//}
