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
#include <numeric>
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // 파일 입출력을 위한 헤더 추가
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>

#define OUT

using namespace std;

vector<int> bfs(const int n, const int m, const vector<vector<int>>& edges, const int s) {
    //build graph - make adj map
    vector<vector<int>> adj(n);
    for (auto& edge : edges)
    {
        adj[edge[0] - 1].push_back(edge[1] - 1); //zero based index
        adj[edge[1] - 1].push_back(edge[0] - 1);
    }

    //BFS search for all nodes
    vector<int> dist(n, -1); //shortest distance from s
    queue<pair<int, int>> q; //{node,dist}
    //start point
    dist[s - 1] = 0;
    q.push({ s - 1,0 });

    while (!q.empty())
    {
        auto [now, cost] = q.front();
        q.pop();

        for (const int next : adj[now])
        {
            //find unvisited next
            if (dist[next] == -1)
            {
                dist[next] = cost + 6;
                q.push({ next,cost + 6 });
            }
        }
    }

    //return result
        //remove start
    vector<int> result(n - 1);
    for (int i = 0; i < n; ++i)
    {
        if (i == s - 1)
        {
            continue;
        }
        else if (i < s - 1)
        {
            result[i] = dist[i];
        }
        else
        {
            result[i - 1] = dist[i];
        }
    }
    return result;
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

   
#pragma region Close
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}