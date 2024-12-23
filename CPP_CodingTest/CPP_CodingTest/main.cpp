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


int dfs(int now,unordered_set<int> visitable, int sheep, int wolf, const vector<int>& info, const vector<vector<int>>& adj)
{
    //visit now
    visitable.erase(now);

    //count type
    if (info[now] == 0)
        ++sheep;
    else
        ++wolf;

    //check current state
    if (wolf >= sheep)
        return sheep;

    int result = sheep;

    //add child to visitable
    for (const int child : adj[now])
    {
        visitable.insert(child);
    }

    for (const int next : visitable)
    {
        result = max(result, dfs(next, visitable, sheep, wolf, info, adj));
    }

    return result;
};



int solution(vector<int> info, vector<vector<int>> edges) {

    const int n = info.size();

    vector<vector<int>> adj(n);
    //build adj
    for (const auto& edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    //find max sheep.
    unordered_set<int> visitable;
    for (const int child : adj[0])
    {
        visitable.insert(child);
    }

    return dfs(0, visitable, 0, 0, info, adj);
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