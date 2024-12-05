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
#include <numeric> //gcd
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // 파일 입출력을 위한 헤더 추가
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>

#define OUT

using namespace std;
	


// Check if it's possible to transport required amount of gold and silver within given time
bool isPossible(const long long time, int gold, int silver, const vector<int>& g,
                const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    const int n = g.size();

    //금, 은 모두 가능한 최대를 옮긴다고 가정
       // 모두가 금위주로 할 때, 모두가 은 위주로 할 때 

    long long totalGold = 0;    // Total transportable gold
    long long totalSilver = 0;  // Total transportable silver
    long long totalMineral = 0; // Total transportable minerals (gold + silver)

    for (int i = 0; i < n; i++)
    {
        //운반 시간 =  t + (운반횟수-1) * 2t  (횟수 >=1)
        //운반횟수 =  floor((totalT - t)/2t + 1)
        long long rounds = 0;
        if (time >= t[i])
        {
            rounds = (time - t[i]) / (2 * t[i]) + 1;
        }

        const long long maxGold = min(1LL * w[i] * rounds, 1LL * g[i]);
        const long long maxSilver = min(1LL * w[i] * rounds, 1LL * s[i]);
        long long maxWeight = min(1LL * w[i] * rounds, 1LL * g[i] + s[i]);

        totalGold += maxGold;
        totalSilver += maxSilver;
        totalMineral += maxWeight;
    }

    // 두가지 상태의 금, 은 무게 가 요구사항을 넘고, 운반 화물양이 모든 요구 화물양을 넘으면 만족
    return  (totalGold >= gold) && (totalSilver >= silver) && (totalMineral >= ((long long)gold + silver));
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    //도시 개수 N <= 1e5 -> NlogN 이하로

    //get lower_bound possible time.
    long long left = 0;
    long long right = 1e9 * 4LL * 1e5; //한계 운반 시간

    //binary search
    while (left < right)
    {
        long long mid = (left + right) / 2;
        if (isPossible(mid, a, b, g, s, w, t))
        {
            //smaller mid
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}


int main() {
	string infile = "./input.txt";
	string outfile = "./output.txt";
#pragma region OpenFile
	ifstream fin(infile); 
	ofstream fout(outfile); 
	if (!fin)
	{
		cerr << "Unable to open input file";
		return 1; // 입력 파일을 열 수 없으면 프로그램 종료
	}
	if (!fout)
	{
		cerr << "Unable to open output file";
		return 1; // 출력 파일을 열 수 없으면 프로그램 종료
	}
#pragma endregion
    cout << solution(10, 10, { 100 }, { 100 }, { 7 }, { 10 });

#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}