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


vector<string> detonateBombs(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<string> result(rows, string(cols, 'O'));

    auto isValid = [rows, cols](int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < cols;
        };

    // Process each cell and clear the bombs and adjacent cells
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 'O')
            {
                result[i][j] = '.';
                if (isValid(i + 1, j)) result[i + 1][j] = '.';
                if (isValid(i - 1, j)) result[i - 1][j] = '.';
                if (isValid(i, j + 1)) result[i][j + 1] = '.';
                if (isValid(i, j - 1)) result[i][j - 1] = '.';
            }
        }
    }

    return result;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if (n == 1)
    {
        // Initial state, no changes
        return grid;
    }

    if (n % 2 == 0)
    {
        // Every even second, the grid is completely filled with bombs
        return vector<string>(grid.size(), string(grid[0].size(), 'O'));
    }

    // Simulate the grid after the first detonation (n % 4 == 3)
    vector<string> firstDetonation = detonateBombs(grid);

    if (n % 4 == 3)
    {
        return firstDetonation;
    }

    // Simulate the grid after the second detonation (n % 4 == 1 and n > 1)
    return detonateBombs(firstDetonation);
}

int main() {

}


