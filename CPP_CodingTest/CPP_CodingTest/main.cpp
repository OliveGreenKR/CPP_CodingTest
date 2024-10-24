#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <locale>
#include <unordered_map>

using namespace std;

int circularRange(int start, int end, int value) {
    int range = end - start + 1;
    return start + (value - start) % range;
}

vector<string> explode(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<string> result(rows, string(cols, 'O'));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 'O')
            {
                result[i][j] = '.';
                if (i > 0) result[i - 1][j] = '.';
                if (i < rows - 1) result[i + 1][j] = '.';
                if (j > 0) result[i][j - 1] = '.';
                if (j < cols - 1) result[i][j + 1] = '.';
            }
        }
    }

    return result;
}

//simulata grid after n seconds,
vector<string> bomberMan(int n, vector<string> grid) {

    if (n == 1)
    {
        return grid;
    }

    //full bombs
    if (n % 2 == 0)
    {
        return vector<string>(grid.size(), string(grid[0].size(), 'O'));
    }

    //after 3seconds
    vector<string> state3 = explode(grid);

    if (n % 4 == 3)
    {
        return state3;
    }
    else
    {
        //after 5 seconds
        return explode(state3);
    }   

}

int main() {

}