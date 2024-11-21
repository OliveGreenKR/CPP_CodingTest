#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <queue>
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

#define OUT

using namespace std;


#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct State
{
    vector<int> rods;  // rod state
    int moves;

    bool operator==(const State& other) const {
        return rods == other.rods;
    }
};

// for state hash
struct StateHash
{
    size_t operator()(const vector<int>& s) const {
        size_t hash = 0;
        for (int i = 0; i < s.size(); i++)
        {
            hash = hash * 4 + s[i];
        }
        return hash;
    }
};

int hanoi(vector<int> posts) {
    const int N = posts.size();
    vector<int> target(N, 1);  //target state

    //initial state
    State initial{ posts, 0 };

    //to find minimum move -> using BFS
    queue<State> q;
    unordered_set<vector<int>, StateHash> visited;

    q.push(initial);
    visited.insert(initial.rods);

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        // is target state and valid order
        if (current.rods == target)
        {
            return current.moves;
        }

        // find all possible rods for each disk
        for (int disk = 0; disk < N; disk++)
        {
            int from_rod = current.rods[disk];

            // check if disk is movable (no smaller disk above)
            bool can_move = true;
            for (int i = 0; i < disk; i++)
            {
                if (current.rods[i] == from_rod)
                {
                    can_move = false;
                    break;
                }
            }

            if (!can_move) continue;

            // try all possible destinations
            for (int to_rod = 1; to_rod <= 4; to_rod++)
            {
                if (to_rod == from_rod) continue;

                // check if destination is valid (no smaller disk)
                bool valid_destination = true;
                for (int i = 0; i < disk; i++)
                {
                    if (current.rods[i] == to_rod)
                    {
                        valid_destination = false;
                        break;
                    }
                }

                if (valid_destination)
                {
                    State next = current;
                    next.rods[disk] = to_rod;
                    next.moves++;

                    if (visited.find(next.rods) == visited.end())
                    {
                        visited.insert(next.rods);
                        q.push(next);
                    }
                }
            }
        }
    }

    return -1;  //no possible ways
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

    const int n = 10;
    vector<int>positions(n, 2);

    cout << hanoi(positions);

#pragma region Close
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}