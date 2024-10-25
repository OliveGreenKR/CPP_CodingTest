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


int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {

    //n번까지의 부분합
    auto set1 = getPartialSumSet(h1);
    auto set2 = getPartialSumSet(h2);
    auto set3 = getPartialSumSet(h3);

    //3 집합의 공통값중 가장 큰 것 찾기.
    int largestCommon = -1; // Assuming all elements are positive

    for (const int& elem : set1)
    {
        if (set2.find(elem) != set2.end() && set3.find(elem) != set3.end())
        {
            largestCommon = max(largestCommon, elem);
        }
    }

    return largestCommon < 0 ? 0 : largestCommon;
}



int main() {

    vector<int> h1 = { 3,2,1,1,1 };
    vector<int> h2 = { 4,3,2 };
    vector<int> h3 = { 1,1,4,1};

    cout << equalStacks(h1, h2, h3);
}