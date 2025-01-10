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

void dfs(int point, int cnt, int sb, const map<int, bool>& pointPool, vector<pair<int, int>>& record)
{
    //if smaller exists, return
    if (record[point] < make_pair(cnt, sb))
    {
        return;
    }

    //go to next in pointPool
        //cnt ++
        // sb -= pointPool[next]

}

vector<int> solution(int target) {

    map<int, bool, greater<int>> pointPool; //{ point, single - bull }

    //record points that can acquire with 1 dart.
        //sb 가 '1' 인것이 우선순위.
            //double, tripple은 존재하지 않는 key에 한해서만 추가
            //s-b는 항상 추가 및 표시


    //memozation  [point] = { dart , (minus) s-b }  -> can choose smaller
    
    //dfs


    return {dart, sumOfsb};
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



#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}

