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
using descendingMap = map<K, V, greater<K>>;

void dfs(int point, int cnt, int sb, const descendingMap<int, bool>& pointPool, vector<pair<int, int>>& record)
{
    //if smaller exists, return
        // samller cnt, larger sb => smaller cnt smaller -sb
    if (point >= record.size() || record[point] <= make_pair(cnt, sb))
    {
        return;
    }
    else
    {
        record[point] = { cnt,sb };
    }

    //go to next in pointPool
    for (const auto [p, s] : pointPool)
    {
        dfs(point + p, cnt + 1, sb - s, pointPool, record);
    }
    return;

}

vector<int> solution(int target) {

    descendingMap<int, bool> pointPool; //{ point, sb }

    //record 1~20
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            int point = i * j;
            if (j == 1)
            {
                pointPool[point] = true;
            }
            else if (pointPool.find(point) == pointPool.end())
            {
                pointPool.insert({ point, false });
            }
        }
        
    }
    //record bull
    pointPool[50] = true;


    //memozation  [point] = { cnt , (minus) s-b }  -> can choose smaller
    const int MAX = 1e5;
    vector<pair<int, int>> record(MAX + 1, {MAX,MAX});
    //dfs
    dfs(0, 0, 0, pointPool, record);

    const auto [cnt, sb] = record[target];
    return {cnt, -sb};
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
    solution(58);


#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}

