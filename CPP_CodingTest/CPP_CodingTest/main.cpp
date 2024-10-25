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
#include <cmath>
#include <limits>

#define OUT

using namespace std;


struct Node {
	int x, y, move;
	Node(int x, int y, int move) : x(x), y(y), move(move) {}
};

//int minimumMoves(vector<string>& grid, int startX, int startY, int goalX, int goalY)
//{
//	vector<vector<int>> cost;
//	//도착지점까지 계속 이동
//		//이동하면서 경로상 위치에 cost[i][j] = ::min( cost[i][j] , move);
//
//		//이동방향 전환시(벽,맵끝) move값 증가
//
//	//도착지점 저장시, 도착지점 cost[i][j] = ::min( cost[i][j] , move)
//		
//}


int minimumMoves(vector<string>& grid, int startX, int startY, int goalX, int goalY) {

    int n = grid.size();
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    cost[startX][startY] = 0;

    // Directions: right, left, down, up
    vector<pair<int, int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int currentCost = cost[x][y];

        // Try each direction
        for (const auto& dir : dirs)
        {
            int nx = x;
            int ny = y;

            // Move until blocked or edge
            while (nx + dir.first >= 0 && nx + dir.first < n &&
                   ny + dir.second >= 0 && ny + dir.second < n &&
                   grid[nx + dir.first][ny + dir.second] != 'X')
            {
                nx += dir.first;
                ny += dir.second;

                // Update cost if new path is cheaper
                if (cost[nx][ny] > currentCost + 1)
                {
                    cost[nx][ny] = currentCost + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return cost[goalX][goalY] == INT_MAX ? -1 : cost[goalX][goalY];
}

int main() {

}