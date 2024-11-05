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

#define OUT

using namespace std;

bool isOverlapping(const pair<int, int>& c1, const int len1, const pair<int, int>& c2, const int len2) {

    int x1 = c1.first, y1 = c1.second;
    int x2 = c2.first, y2 = c2.second;

    // Vertical line of cross1 intersects with horizontal line of cross2
    if (x1 >= x2 - len2 && x1 <= x2 + len2 &&
        y2 >= y1 - len1 && y2 <= y1 + len1)
    {
        return true;
    }

    // Horizontal line of cross1 intersects with vertical line of cross2
    if (y1 >= y2 - len2 && y1 <= y2 + len2 &&
        x2 >= x1 - len1 && x2 <= x1 + len1)
    {
        return true;
    }

    // Horizontal lines overlap
    if (y1 == y2 &&
        max(x1 - len1, x2 - len2) <= min(x1 + len1, x2 + len2))
    {
        return true;
    }

    // Vertical lines overlap
    if (x1 == x2 &&
        max(y1 - len1, y2 - len2) <= min(y1 + len1, y2 + len2))
    {
        return true;
    }

    return false;
}
int twoPluses(vector<string> grid) {
    /*horizontal length == vertical length
        1. odd length
        2. cross the middle each other
        3. pluses cannot be overlapped

    Find the '2' largest plus that can be drawn on 'good' cells.
    return : maximum product of their areas.
    */

    const int rows = grid.size();
    const int cols = grid[0].size();
    //record the maximum extension length each directions
    vector<vector<int>> up(rows, vector<int>(cols, 0));
    vector<vector<int>> down(rows, vector<int>(cols, 0));
    vector<vector<int>> left(rows, vector<int>(cols, 0));
    vector<vector<int>> right(rows, vector<int>(cols, 0));

    //get maximum extension length DP
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 'G')
            {
                up[i][j] = (i > 0 ? up[i - 1][j] + 1 : 1);
                left[i][j] = (j > 0 ? left[i][j - 1] + 1 : 1);
            }
        }
    }

    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            if (grid[i][j] == 'G')
            {
                down[i][j] = (i < rows - 1 ? down[i + 1][j] + 1 : 1);
                right[i][j] = (j < cols - 1 ? right[i][j + 1] + 1 : 1);
            }
        }
    }

    //all possible + to each cells
    vector<pair<int, pair<int, int>>> pluses;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 'G')
            {
                int maxSize = min({ up[i][j], down[i][j], left[i][j], right[i][j] });
                for (int size = 0; size < maxSize; ++size)
                {
                    int area = 1 + 4 * size;
                    pluses.emplace_back(area, make_pair(i, j));
                }
            }
        }
    }

    //sort descending order
    ::sort(pluses.rbegin(), pluses.rend());

    //find the answers
    int maxProduct = 0;
    for (int i = 0; i < pluses.size(); ++i)
    {
        for (int j = i + 1; j < pluses.size(); ++j)
        {
            int area1 = pluses[i].first;
            int area2 = pluses[j].first;
            auto [x1, y1] = pluses[i].second;
            auto [x2, y2] = pluses[j].second;
            // get the length of arms
            int size1 = (area1 - 1) / 4;
            int size2 = (area2 - 1) / 4;

            // Check if the two pluses overlap
            
            if (isOverlapping(pluses[i].second, size1, pluses[j].second, size2) == false)
            {
                maxProduct = max(maxProduct, area1 * area2);
            }
        }
    }

    return maxProduct;

}

int main() {

}


