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

using namespace std;

// Function to calculate circular range
int circularRange(int start, int end, int value) {
    int range = end - start + 1;
    return start + (value - start) % range;
}

// Function to check if a string is valid by removing at most one character
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    ranked.erase(std::unique(ranked.begin(), ranked.end()), ranked.end());

    std::vector<int> result;
    int n = ranked.size();

    for (int p : player)
    {
        auto it = ::lower_bound(ranked.begin(), ranked.end(),p,::greater<int>());

        int rank = it - ranked.begin() + 1;
        result.push_back(it -ranked.begin() +1);
    }

    return result;
}



int main() {
    vector<int> ranked = { 100,90,90,80 };
    vector<int> player = { 70,80,105};

    climbingLeaderboard(ranked, player);

}