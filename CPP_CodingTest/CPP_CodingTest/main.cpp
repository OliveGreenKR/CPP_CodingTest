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

string gridSearch(vector<string> G, vector<string> P) {
    int R = G.size();    // Grid rows
    int C = G[0].size(); // Grid columns
    int r = P.size();    // Pattern rows
    int c = P[0].size(); // Pattern columns

    //2D sliding window 

    //Find the possible starting point in the grid.
    for (int i = 0; i <= R - r; i++)
    {
        for (int j = 0; j <= C - c; j++)
        {

            bool match = true;
            //check Pattern matches with  at grid[i][j]
            for (int x = 0; x < r; x++)
            {
                if (G[i + x].substr(j, c) != P[x])
                {
                    match = false;
                    break;
                }
            }
            //whole pattern found
            if (match)
                return "YES";
        }
    }
    return "NO";
}
int main() {

}


