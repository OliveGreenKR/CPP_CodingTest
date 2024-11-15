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


int dfs(int x, int y, vector<string>& matrix){
    static const vector<pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };
    const int n = matrix.size();
    const int m = matrix[0].size();

    // If destination found
    if (matrix[x][y] == '*') 
        return 0;

    // Mark current cell as visited
    matrix[x][y] = 'X';

    // Count available paths
    int availablePaths = 0;
    vector<pair<int, int>> nextPaths;

    for (const auto& [dx, dy] : directions)
    {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && /*!visited[x][y]*/
            matrix[nx][ny] != 'X')
        {
            availablePaths++;
            nextPaths.push_back({ nx, ny });
        }
    }

    // Try each available path
    for (const auto& [nx, ny] : nextPaths)
    {
        int result = dfs(nx, ny, matrix);
        if (result != -1)
        {
            return result + (availablePaths > 1 ? 1 : 0);
        }
    }
    return -1;
    };

string countLuck(vector<string>& matrix, int k) {
    static const vector<pair<int, int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
    const int n = matrix.size();
    const int m = matrix[0].length();

    // Find starting position
    pair<int, int> start;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 'M')
            {
                start = { i, j };
                break;
            }
        }
    }

    // Get number of wand waves needed
    int wandWaves = dfs(start.first, start.second,matrix);

    return wandWaves == k ? "Impressed" : "Oops!";
}
int main() {

#pragma region OpenFile
    ifstream inputFile("./input.txt"); // 입력 파일 열기
    ofstream outputFile("./output.txt"); // 출력 파일 열기
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
    int t, n, m;
    inputFile >> t;

    
    for (int i = 0; i < t; ++i)
    {
        int n, m;
        inputFile >> n >> m;
        vector<string>matrix(n);

        for (int j = 0; j < n; ++j)
        {
            inputFile >> matrix[j];
        }
        int k;
        inputFile >> k;
        cout << i << " : " << countLuck(matrix, k) << endl;
    }
    //outputFile << result << "\n"; // 결과를 출력 파일에 쓰기
#pragma region Close
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}

//Impressed
//Impressed
//Impressed
//Impressed
//Oops!
//Impressed