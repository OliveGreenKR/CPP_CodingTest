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

pair<int, int> findMinGroups(const int m, const int now, const int parent, const vector<vector<int>>& adj, const vector<int>& nodeinfo)
{
    //크기가 큰 서브부터 -> maxHeap 사용
    priority_queue<int> subHeap;

    int sum = nodeinfo[now];
    int groups = 1;

    //dfs 탐색으로 subTree의 합
    for (auto next : adj[now])
    {
        if (next == parent)
            continue;
        auto [gcount, subSum] = findMinGroups(m, next, now, adj, nodeinfo);
        sum += subSum;
        groups += gcount - 1;
        subHeap.push(subSum);
    }

    //divide groups
    while (!subHeap.empty() && sum > m)
    {
        ++groups;
        sum -= subHeap.top(); //biggest subTree
        subHeap.pop();
    }
    return { groups, sum }; //return cuurent TreeSum
}



//그룹 개수 k일때 가장 큰 집합의 최소 크기 반환
int binarySearch(int k, const vector<int>& nodeinfo, const vector<vector<int>>& adj)
{
    //root = 0
    //집합의 크기 범위 [1..all]
    int left = 1;
    int right = 1e8;
    int mid = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        //가장 큰 집합의 크기가 mid 이하일때의 그룹 개수
        auto [gcount, sums] = findMinGroups(mid, 0, -1, adj, nodeinfo);

        //k 초과의 그룹 생성 가능 -> 집합 크기 증가
        if (gcount > k)
            left = mid + 1;

        //k 이하의 그룹 생성 가능 -> 집합 크기 감소
        if (gcount <= k)
            right = mid; //mid값을 포함해야 함
    }

    return mid;
}


int solution(int k, vector<int> num, vector<vector<int>> links) {

    const int n = num.size();

    vector<vector<int>> adj(n);
    //build bidirectional adj[i]
    for (int i = 0; i < n ; ++i)
    {
        const auto link = links[i];

        if (link[0] >= 0)
        {
            adj[i].push_back(link[0]);
            adj[link[0]].push_back(i);
        }
        if (link[1] >= 0)
        {
            adj[i].push_back(link[1]);
            adj[link[1]].push_back(i);
        }
    }

    return binarySearch(k, num, adj);
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
    int k = 3;
    vector<int> num = { 12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1 };
    vector<vector<int>> links = { {-1, -1}, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 8, 5 }, { 2, 10 }, { 3, 0 }, { 6, 1 }, { 11, -1 }, { 7, 4 }, { -1, -1 }, { -1, -1 } };
    
    cout << solution(3, num,links);

#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}