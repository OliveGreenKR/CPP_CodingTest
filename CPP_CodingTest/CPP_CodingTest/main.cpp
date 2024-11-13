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

#define OUT

using namespace std;

int dfs(vector<vector<int>>& matrix, int i, int j) {
    int m = matrix.size();
    int n = matrix[0].size();

    //can not visit
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0)
    {
        return 0;
    }

    //visit
    matrix[i][j] = 0; // Mark the cell as visited

    //get Size of Graph
    int size = 1;
    //dfs to all 8 directions
    size += dfs(matrix, i - 1, j - 1); // Up-Left
    size += dfs(matrix, i - 1, j);   // Up
    size += dfs(matrix, i - 1, j + 1); // Up-Right
    size += dfs(matrix, i, j - 1);   // Left
    size += dfs(matrix, i, j + 1);   // Right
    size += dfs(matrix, i + 1, j - 1); // Down-Left
    size += dfs(matrix, i + 1, j);   // Down
    size += dfs(matrix, i + 1, j + 1); // Down-Right

    return size;
}

int connectedCell(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int maxSize = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //Can visit
            if (matrix[i][j] == 1)
            {
                int size = dfs(matrix, i, j);
                maxSize = max(maxSize, size);
            }
        }
    }

    return maxSize;
}


int main() {

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


    //inputFile >> l >> r; // 각 쿼리에서 l과 r 읽기
    int k = 2;
    vector<int> pair = { 1,5,3,4,2 };
    cout << pairs(2, pair);

    //outputFile << result << "\n"; // 결과를 출력 파일에 쓰기
    
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기
    

    //8,705,701,581,298,678
    return 0;
}

//int main2()
//{
//}
