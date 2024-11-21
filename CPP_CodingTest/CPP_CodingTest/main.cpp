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


//toto 첫번째 조건을 위해서는
    // not (모두 같은 수 ||  2개씩 같은 수) 이어야함...
        //3 번째 까지는 일반적인 오름차순 선택
            //4번째에서 2쌍 수를 제거해야함.

//정상적인 오름차순 -  [모두 같은 수 = A ]  - [2쌍]

//2쌍수 는 오름차순이기에
    //AACC, AABB만 가능
//즉 제거해야하는 경우

int solution(int n, int m, vector<vector<int>>& dp, vector<int>&p)
{
    if (n < 0 || n > 3 || m < 1) 
        return 0;

    if (m > p[n])
        dp[n][m] = 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    dp[n][m] = 0;

    for (int i = 1; i <= m; ++i)
    {
        dp[n][m] += solution(n - 1, i, dp,p);
    }

    return dp[n][m];
}

int beautifulQuadruples(int a, int b, int c, int d) {
    vector<int> p = { a,b,c,d };
    sort(p.begin(), p.end());

    vector<vector<int>> dp(4, vector<int>(3000 + 1, -1));
    for (int i = 1; i <= p[0]; ++i)
    {
        dp[0][i] = 1;
    }

    int result = 0;
    for (int m = 1; m <= p[3]; ++m)
        result += solution(3, m, dp, p);

    //for BitWise condition
    //[AA][CC]  , when [C] is lower than 'C'
    return result - p[0]*p[2];

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

    cout << beautifulQuadruples(1, 2, 3, 4);
    /*Do Something*/

#pragma region Close
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}