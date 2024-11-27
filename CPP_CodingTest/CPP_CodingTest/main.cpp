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



using namespace std;
#define OUT


int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> lakes) {

    //build portal map
    unordered_map<int, int> portalMap;
    
    for (const auto ladder : ladders)
    {
        portalMap[ladder[0]] = ladder[1];
    }

    for (const auto lake : lakes)
    {
        portalMap[lake[0]] = lake[1];
    }

    const int INF = INT32_MAX;

    //BFS for shortes path to destination

    vector<int> dist(101, INF);
    queue<pair<int, int>> q; //[pos][diceCost]
    
    //start
    q.push({ 1,0 }); 
    dist[1] = 0;

    while (!q.empty())
    {
        auto [now, cost] = q.front();
        q.pop();

        dist[now] = cost; //cost < dist[now

        if (now == 100) //destination
            break;

        //move with dice
        for (int i = 1; i <= 6; ++i)
        {
            int next = now + i;

            if (portalMap.find(next) != portalMap.end())
            {
                next = portalMap[next];
            }

            //visit next
            if (next <= 100 && next >= 1 && cost+1 < dist[next])
            {
                q.push({ next,cost + 1 });
            }
            
        }

    }

    return dist[100] == INF ? -1 : dist[100];
}


int main() {
 ifstream fin("./input.txt"); // 입력 파일 열기
ofstream fout("./output.txt"); // 출력 파일 열기
#pragma region OpenFile
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
    int q;
    fin >> q;

    for (int i = 0; i < q; ++i)
    {
        int l;
        fin >> l;
        vector<vector<int>> ladders(l);
        for (int j = 0; j < l; ++j)
        {
            int u, v;
            fin >> u >> v;
            ladders[j] = { u,v };
        }

        int s;
        fin >> s;
        vector<vector<int>> snakes(s);
        for (int k = 0; k < s; ++k)
        {
            int u, v;
            fin >> u >> v;
            snakes[k] = { u,v };
        }

        cout << quickestWayUp(ladders, snakes) << "\n";  //2 3 2
    }

   
#pragma region Close
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}