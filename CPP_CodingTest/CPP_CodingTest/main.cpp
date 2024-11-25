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


class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int setCount;

public:
    DisjointSet(int n) : parent(n), rank(n, 0), size(n, 1), setCount(n) {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            if (rank[rootX] == rank[rootY])
            {
                rank[rootX]++;
            }
            setCount--;
        }
    }

    int getSetSize(int x) {
        return size[find(x)];
    }

    vector<int> getAllSetSizes() {
        vector<bool> isRoot(parent.size(), false);
        vector<int> setSizes;

        for (int i = 0; i < parent.size(); i++)
        {
            int root = find(i);
            if (!isRoot[root])
            {
                setSizes.push_back(size[root]);
                isRoot[root] = true;
            }
        }
        return setSizes;
    }
};

long long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if (n == 1) return c_lib;

    if (c_lib <= c_road)
    {
        return (long long)n * c_lib;
    }

    // Disjoint Set
    DisjointSet ds(n);

    for (const auto& road : cities)
    {
        ds.unite(road[0] - 1, road[1] - 1); // 0-based index
    }

    auto setSizes = ds.getAllSetSizes();

    long long totalCost = 0;
    for (int size : setSizes)
    {
        totalCost += c_lib + (long long)(size - 1) * c_road;
    }

    return totalCost;
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
    int q;

    inputFile >> q;

    for (int i = 0; i < q; i++)
    {
        int n, m, l, r;
        inputFile >> n >> m >> l >> r;

        vector<vector<int>> cities(m, vector<int>(2,-1));
        for (auto& edge :cities)
        {
            inputFile >> edge[0] >> edge[1];
        }
        cout << roadsAndLibraries(n, l, r, cities) << "\n";
    }
   
   
#pragma region Close
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}