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
#include <cmath>

#define OUT

using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    //maximum distance with moving directions
    int up = n - r_q;
    int down = r_q - 1;
    int right = n - c_q;
    int left = c_q - 1;
    int up_right = min(up, right);
    int up_left = min(up, left);
    int down_right = min(down, right);
    int down_left = min(down, left);

    for (const auto& obs : obstacles)
    {
        int r_o = obs[0];
        int c_o = obs[1];

        
        if (c_o == c_q) //Up,Down
        { 
            if (r_o > r_q) 
            { 
                //Up
                up = min(up, r_o - r_q - 1);
            }
            else
            { 
                //Down
                down = min(down, r_q - r_o - 1);
            }
        }
        else if (r_o == r_q) //Right, Left
        { 
            if (c_o > c_q)
            { 
                //right
                right = min(right, c_o - c_q - 1);
            }
            else
            { 
                //left
                left = min(left, c_q - c_o - 1);
            }
        }
        else if (abs(r_o - r_q) == abs(c_o - c_q)) //diagonal
        { 
            if (r_o > r_q && c_o > c_q)
            { 
                //Upper Right
                up_right = min(up_right, r_o - r_q - 1);
            }
            else if (r_o > r_q && c_o < c_q)
            { 
                //Upper Left
                up_left = min(up_left, r_o - r_q - 1);
            }
            else if (r_o < r_q && c_o > c_q)
            { // Lower Right
                down_right = min(down_right, r_q - r_o - 1);
            }
            else if (r_o < r_q && c_o < c_q)
            { // Lower Left
                down_left = min(down_left, r_q - r_o - 1);
            }
        }
    }

    int total_attacks = up + down + left + right + up_right + up_left + down_right + down_left;

    return total_attacks;
}



int main() {


    return 0;
}


