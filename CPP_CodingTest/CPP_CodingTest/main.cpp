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

#define OUT

using namespace std;

// Function to find max values in subarrays of length d
vector<int> FindMaxValOnSubArrays(const vector<int>& arr, int d) {
    deque<int> MaxIdxDq;
    vector<int> maxVals;

    // Sliding window to find maximum in every subarray of size d
    for (int i = 0; i < arr.size(); ++i)
    {
        // Remove elements not within the window
        if (!MaxIdxDq.empty() && MaxIdxDq.front() == i - d)
        {
            MaxIdxDq.pop_front();
        }

        // Remove elements smaller than the current element
        while (!MaxIdxDq.empty() && arr[MaxIdxDq.back()] <= arr[i])
        {
            MaxIdxDq.pop_back();
        }

        MaxIdxDq.push_back(i);

        // Once we've processed the first d elements, start recording max values
        if (i >= d - 1)
        {
            maxVals.push_back(arr[MaxIdxDq.front()]);
        }
    }

    return maxVals;
}

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> result;

    for (int q : queries)
    {
        vector<int> maxVals = FindMaxValOnSubArrays(arr, q);
        // Find the minimum value among the max values
        result.push_back(*min_element(maxVals.begin(), maxVals.end()));
    }

    return result;
}

int main() {
    vector<int> arr = { 1, 3, 2, 4, 6, 5, 8, 7 };
    vector<int> queries = { 3, 4 };

    vector<int> result = solve(arr, queries);
    for (int res : result)
    {
        cout << res << " ";
    }

    return 0;
}


int main() {

}