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


int solutionEx(vector<int> info, vector<vector<int>> edges) {
    const int n = info.size();

    //build adj list
    vector<vector<int>> adj(n);
    for (const auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> wolfcnt(n, INT32_MAX);
    //BFS for check wolfs
    queue<pair<int, int>> q; //[node][wolfcnt]
    q.push({ 0,0 });

    while (!q.empty())
    {
        auto [now, cnt] = q.front();
        q.pop();

        if (info[now] == 1) //wolf
            ++cnt;
        else
        {
            wolfcnt[now] = cnt; //record only sheep
        }

        //visit next
        for (const int next : adj[now])
        {
            q.push({ next,cnt });
        }
    }

    //sort wolfcnt - ascending
    sort(wolfcnt.begin(), wolfcnt.end());

    int wolf = 0;
    int sheep = 0;
    for (const int cnt : wolfcnt)
    {
        //avaiable sheep
        if (cnt == 0 || wolf + cnt < sheep)
        {
            ++sheep;
            wolf += cnt;
        }
        else
            break;

    }

    return sheep;
}


//

int solution(vector<int> info, vector<vector<int>> edges) {
    const int n = info.size();


    //누적합 =  늑대 -1, 양 +1
    //dp[i][j]  =  i에서 j까지 가는 <최대 누적합,양의 개수>
    vector < vector<pair<int, int>> dp()

        //build base dp with edge
        vector<vector<int>> adj(n);
    for (const auto edge : edges)
    {

    }



    //floyd-warshall kij
    for (int i = 1; i < n; ++i)
    {

    }


    return 0;
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