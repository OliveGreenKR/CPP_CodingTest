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
public: 
    DisjointSet(int n) : parent(n), rank(n, 0), size(n, 1), setCount(n) {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
private :
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int setCount;

public:

    int Find(int u)
    {
        if (parent[u] != u)
            parent[u] = Find(parent[u]);

        return parent[u];
    }

    void Union(const int u, const int v)
    {
        int ru = Find(u);
        int rv = Find(v);

        if (ru == rv)
            return;

        //union by rank
        if (rank[ru] < rank[rv])
            swap(ru, rv);

        //ru is larger
        parent[rv] = ru;
        size[ru] += size[rv];
        if (rank[ru] == rank[rv])
        {
            rank[ru]++;
        }
        setCount--;
    }

    vector<int> getAllSetSizes() {
        vector<bool> visited(parent.size(), false);
        vector<int> setSizes;

        for (int i = 0; i < parent.size(); i++)
        {
            int root = Find(i);
            if (!visited[root])
            {
                setSizes.push_back(size[root]);
                visited[root] = true;
            }
        }
        return setSizes;
    }

};

long long journeyToMoon(const int n, vector<vector<int>> astronaut) {

    //make disjointSet
    DisjointSet Astro(n);

    for (const auto& astro : astronaut)
    {
        Astro.Union(astro[0], astro[1]);
    }

    
    vector<int> allSets = Astro.getAllSetSizes();

    long long AllPairs = (long long)n * (n - 1) / 2;

    for (long long m : allSets)
    {
        AllPairs -= max(0LL, m * (m - 1) / 2);
    }

    return AllPairs;

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