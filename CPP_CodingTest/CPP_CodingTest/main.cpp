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

int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {
    const int INF = INT32_MAX;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> fish_at_node(n + 1, 0);

    // Bitmask for fishState
    for (int i = 1; i <= n; i++)
    {
        stringstream ss(centers[i - 1]);
        int num_types;
        ss >> num_types;  // # of fish Type 

        // fish Types
        for (int j = 0; j < num_types; j++)
        {
            int fish;
            ss >> fish;
            fish_at_node[i] |= (1 << (fish - 1));  // 0-based Bitmask
        }
    }

    // Construct Graph - adj map
    for (const auto& road : roads)
    {
        int u = road[0], v = road[1], w = road[2];
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    // dp[node][fish_mask] = minimum time to reach node with fish_mask
    vector<vector<int>> dp(n + 1, vector<int>(1 << k, INF));

    // start point
    dp[1][fish_at_node[1]] = 0;

    //BFS
    queue<int> nodesToVisit;
    nodesToVisit.push(1);

    // minumum time for each node in all possible fish State
    while (!nodesToVisit.empty())
    {
        int curr = nodesToVisit.front();
        nodesToVisit.pop();

        //current node's  all FishState 
        for (int mask = 0; mask < (1 << k); mask++)
        {
            if (dp[curr][mask] == INF) continue;

            //find Next
            for (auto [next, time] : graph[curr])
            {
                //visit
                int new_mask = mask | fish_at_node[next];

                // update minimum time for Next
                if (dp[next][new_mask] > dp[curr][mask] + time)
                {
                    dp[next][new_mask] = dp[curr][mask] + time;
                    nodesToVisit.push(next);
                }
            }
        }
    }

    // Find all Possible fish State pairs in 'n'
    int answer = INF;
    int all_fish = (1 << k) - 1;  //target fish state

    for (int mask1 = 0; mask1 < (1 << k); mask1++)
    {
        if (dp[n][mask1] == INF) continue;

        for (int mask2 = 0; mask2 < (1 << k); mask2++)
        {
            if (dp[n][mask2] == INF) continue;

            //check all fish state
            if ((mask1 | mask2) == all_fish)
            {
                answer = min(answer, max(dp[n][mask1], dp[n][mask2]));
            }
        }
    }

    return answer == INF ? -1 : answer;
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