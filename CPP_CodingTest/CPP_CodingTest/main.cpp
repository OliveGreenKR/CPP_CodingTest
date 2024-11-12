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

int hackerlandRadioTransmitters(vector<int> x, int k) {
    const int n = x.size();
    sort(x.begin(), x.end());

    int transmitter = 0;
    auto uncoveredCity = x.begin();

    while (uncoveredCity != x.end())
    {
        //transmitter  = lower_bound( smallest uncoveredCity + k )
        //next smallest uncovered city =  
        //          upper_bound(recently installed transmitter + k)
        transmitter++;
        int nextlimit = *uncoveredCity + k;
        auto nextCity = upper_bound(uncoveredCity, x.end(), nextlimit);
  
        //there is a city can cover itself.
        if (*(nextCity-1) <= nextlimit )
        {
            nextlimit = *(--nextCity) + k;
            nextCity = upper_bound(nextCity, x.end(), nextlimit);
        }
        
        uncoveredCity = nextCity;
    }

    return transmitter;
}


int main2() {

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

int main()
{
    //vector<int> city = { 7, 2, 4, 6, 5, 9, 12, 11 };
    vector<int> city = { 9, 5, 4, 2, 6, 15, 12 };

    cout << hackerlandRadioTransmitters(city, 2);
}
