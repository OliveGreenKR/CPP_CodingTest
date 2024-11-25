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
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>

#define OUT

using namespace std;

void printShortestPath(const int n, int i_start, int j_start, int i_end, int j_end) {

    using Vector2 = pair<int, int>;
    const vector<Vector2> directions = { {-2,-1},{-2,1},{0,2},{2,1},{2,-1},{0,-2} };
    const vector<string>  directionStrings = { "UL", "UR", "R", "LR", "LL", "L" };

    vector<vector<int>> dirRecord(n, vector<int>(n, -1)); //record direction's index

    queue<Vector2> q;

    q.push({ i_start, j_start });

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == i_end && y == j_end)
        {
            break;
        }

        for (int i = 0; i < directions.size(); ++i)
        {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            //visit check
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dirRecord[nx][ny] == -1)
            {
                q.push({ nx, ny });
                dirRecord[nx][ny] = i;  //record directions
            }
        }
    }

    if (dirRecord[i_end][j_end] == -1)
    {
        cout << "Impossible" << endl;
        return;
    }
       
	
    Vector2 now(i_end, j_end);
    Vector2 start(i_start, j_start);
    stack<string> shortest_path;
    //backtrack
    int cost = 0;
    while (now != start)
    {
        cost++;
        int direcIdx = dirRecord[now.first][now.second];
        shortest_path.push(directionStrings[direcIdx]);
        now.first -= directions[direcIdx].first;
        now.second -= directions[direcIdx].second;
    }


    cout << cost << "\n";
    while (!shortest_path.empty())
    {
        cout << shortest_path.top() << " ";
        shortest_path.pop();
    }
    cout << endl;
}


int main() {
 ifstream inputFile("./input.txt"); // �Է� ���� ����
ofstream outputFile("./output.txt"); // ��� ���� ����
#pragma region OpenFile
    if (!inputFile)
    {
        cerr << "Unable to open input file";
        return 1; // �Է� ������ �� �� ������ ���α׷� ����
    }
    if (!outputFile)
    {
        cerr << "Unable to open output file";
        return 1; // ��� ������ �� �� ������ ���α׷� ����
    }
#pragma endregion

    printShortestPath(7, 6, 6, 0, 1); //UL UL UL L
    printShortestPath(6, 5, 1, 0, 5); //impossible
    printShortestPath(7, 0, 3, 4, 3); //LR LL
    

#pragma region Close
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}