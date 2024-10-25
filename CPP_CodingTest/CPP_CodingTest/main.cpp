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
#include <unordered_set>
#include <numeric>

using namespace std;

#define OUT

// Function to calculate circular range
int circularRange(int start, int end, int value) {
    int range = end - start + 1;
    return start + (value - start) % range;
}

unordered_set<int> getPartialSumSet(vector<int>& target)
{
    unordered_set<int> result;
    int sum = 0;
    for(auto it = target.rbegin(); it != target.rend(); ++it)
    {
        sum += *it;
        result.insert(sum);
    }

    return result;
}


#include <vector>
#include <numeric> // for accumulate

// Function to find the maximum possible height where all stacks have equal height
int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3) {
    // Calculate the total height of each stack
    int height1 = std::accumulate(h1.begin(), h1.end(), 0);
    int height2 = std::accumulate(h2.begin(), h2.end(), 0);
    int height3 = std::accumulate(h3.begin(), h3.end(), 0);

    int idx1 = 0, idx2 = 0, idx3 = 0;

    // While the heights of the stacks are not equal, keep removing cylinders from the tallest stack
    while (!(height1 == height2 && height2 == height3))
    {
        if (height1 >= height2 && height1 >= height3)
        {
            height1 -= h1[idx1++];
        }
        else if (height2 >= height1 && height2 >= height3)
        {
            height2 -= h2[idx2++];
        }
        else
        {
            height3 -= h3[idx3++];
        }
    }

    return height1; // or height2 or height3, they should all be equal at this point
}




int main() {

    vector<int> h1 = { 3,2,1,1,1 };
    vector<int> h2 = { 4,3,2 };
    vector<int> h3 = { 1,1,4,1};

    cout << equalStacks(h1, h2, h3);
}