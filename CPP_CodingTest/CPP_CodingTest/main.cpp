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

template <typename K, typename V>
using pointMap = unordered_map<K, V>;

vector<int> solution(int target) {

    //under 311, 50is better than 60

    const int MAX = 310;

    //한번에 얻을 수 있는 점수
    pointMap<int, bool> oneshotPoint; //[point]{sb} 
    //record 1~20
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            int point = i * j;
            if (j == 1)
            {
                oneshotPoint[point] = true;
            }
            else if (oneshotPoint.find(point) == oneshotPoint.end())
            {
                oneshotPoint.insert({ point, false });
            }
        }

    }
    //record bull
    oneshotPoint[50] = true;


    //dp for darts, -sb
    vector<pair<int, int>> dp(MAX + 1, { INT32_MAX,0 });

    for (const auto [point, sb] : oneshotPoint)
    {
        //record oneshot point, {1,-sb}
        dp[point] = { 1,-(int)sb };
    }

    //record dp
    //작은수부터 310 까지 최상의 점수 기록 , 작을수록 이득

    for (int t = 1; t <= MAX; ++t)
    {
        //a=한 번에 얻을 수 잇는 점수,
        //dp[T] = min(dp[T-a])+{1,sb[a]}
        for (const auto [point, sb] : oneshotPoint)
        {
            if (t - point > 0)
            {
                pair<int, int> tmp1 = dp[t - point];
                pair<int, int> tmp2 = { tmp1.first + 1, tmp1.second - sb };
                dp[t] = ::min(dp[t], tmp2);
            }
        }
    }

    int move = target - MAX > 0 ? ceil((target - MAX) / 60.f) : 0;
    int left = target - 60 * move;
    auto [cnt, msb] = dp[left];
    return { cnt + move , -msb };

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
    solution(100000);

#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}

