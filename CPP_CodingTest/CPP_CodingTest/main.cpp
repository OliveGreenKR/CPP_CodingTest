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
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>

#define OUT

using namespace std;

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> result(n-1, vector<int>(n-1,-1));
    vector<pair<int, int>> moves = { {1,1},{1,-1},{-1,1},{-1,-1} };
    // Iterate over all possible (a, b) pairs
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b < n; b++)
        {
            // Create a chessboard for each (a, b) pair
            vector<vector<int>> chessboard(n, vector<int>(n,-1));

            // Perform BFS starting from (0, 0)
            queue<pair<int, int>> q;
            chessboard[0][0] = 0;
            q.push({ 0, 0 });

            while (!q.empty())
            {
                pair<int, int> curr = q.front();
                q.pop();
                int currX = curr.first;
                int currY = curr.second;

                // Check all possible moves from the current position
                for (const auto& move : moves)
                {
                    auto Visit = [&](const int newX, const int newY) 
                        {
                            if (newX >= 0 && newX < n && newY >= 0 && newY < n && chessboard[newX][newY] == -1 && chessboard[newY][newX] == -1)
                            {
                                chessboard[newX][newY] = chessboard[currX][currY] + 1;
                                q.push({ newX, newY });

                                // If the destination is reached, store the minimum moves and break
                                if (newX == n - 1 && newY == n - 1)
                                {
                                    result[a - 1][b - 1] = chessboard[newX][newY];
                                    return true;
                                }
                            }
                            return false;
                        };

                    if (Visit(currX + a * move.first, currY + b * move.second))
                        break;
                    if (Visit(currX + b * move.first, currY + a * move.second))
                        break;
                    
                }
            }
        }
    }

    // Fill the symmetric entries in the result matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            result[j][i] = result[i][j] = max(result[j][i], result[i][j]);
        }
    }

    return result;
}

int main() {

    ifstream inputFile("./input.txt"); // �Է� ���� ����
    ofstream outputFile("./output.txt"); // ��� ���� ����
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


    //inputFile >> l >> r; // �� �������� l�� r �б�
    
    int n;
    
    inputFile >> n ;
    auto result = knightlOnAChessboard(n);
    for (auto& row : result)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
    
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
    

    //8,705,701,581,298,678
    return 0;
}

//int main2()
//{
//}
