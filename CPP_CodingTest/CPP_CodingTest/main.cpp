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
#include <sstream>

#define OUT

using namespace std;


#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

long long beautifulQuadruples(int a, int b, int c, int d) {
    vector<int> p = { a,b,c,d };
    sort(p.begin(), p.end());

    const int MAX = 4096;
    vector<int> cnt(MAX, 0);

    //the number of {ZW}
    long long countZW = 0;


    //all possible {ZW} and recore Z^W
    for (int z = 1; z <= p[2]; ++z)
    {
        for (int w = z; w <= p[3]; ++w)
        {
            ++cnt[z ^ w];
            ++countZW;
        }
    }

    long long result = 0;

    for (int y = 1; y <= p[1]; ++y)
    {
        for (int x = 1; x <= min(p[0], y); ++x)
        {
            //answer += {ZW} - {ZW | Z^W==X^Y}
            result += countZW - cnt[x ^ y];
        }
        //update possible{ZW} for next y
            // Delete pairs that were possible with the current y
        for (int w = y; w <= p[3]; ++w)
        {
            --cnt[y ^ w];
            --countZW;
        }
    }

    return result;
}

long long countAllPermutations(int a, int b, int c, int d) {
    vector<int> p = { a,b,c,d };
    sort(p.begin(), p.end());

    long long allCount = 0;

    for (int x = 1; x <= p[0]; x++)
    {
        for (int y = x; y <= p[1]; y++)
        {
            int minZ = y;   
            int maxZ = p[2];   

            allCount += ((long long)(maxZ - minZ + 1) * (p[3] - minZ + 1) -
                      ((long long)(maxZ - minZ + 1) * (maxZ - minZ)) / 2);
        }
    }

    return allCount;
}

int main() {
 ifstream inputFile("./input.txt"); // 입력 파일 열기
ofstream outputFile("./output.txt"); // 출력 파일 열기
#pragma region OpenFile
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
#pragma endregion


    // 마지막 위치(3)부터 시작

    //cout << beautifulQuadruples(360, 896, 1927, 2047);
    cout << beautifulQuadruples(360, 896, 1927, 2047) << endl;
    cout << beautifulQuadruples(1, 2, 3, 4);

    //2047 1927 360 896    =>   301271960180
    // 전체 종류 수 : 301438994250   // 301438300530

#pragma region Close
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}