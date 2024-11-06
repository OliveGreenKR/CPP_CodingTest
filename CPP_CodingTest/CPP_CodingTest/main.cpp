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

int lilysHomework(vector<int> arr) {

    vector<int> ascending(arr);
    vector<int> descending(arr);

    sort(ascending.begin(), ascending.end());
    sort(descending.rbegin(), descending.rend());

    //find cycle
        //need to get element's current idx -> unordered_map
        //need to check visit

    const int n = arr.size();
    unordered_map<int, int> indexMap;
    

    //make index table
    for (int i = 0; i < n; ++i)
    {
        indexMap[arr[i]] = i;
    }

    auto findMinSwap = [&indexMap,&n,&arr](const vector<int>& sorted)
        {
            int swaps;
            vector<bool> visited(n, false);
            int swaps = 0;
            //find cycles and count swpas 
            for (int i = 0; i < n; ++i)
            {
                if (visited[i] || arr[i] == sorted[i])
                {
                    continue;
                }
                int cycles_count = 0;
                int j = i;
                while (visited[j] != true)
                {
                    visited[j] = true;
                    j = indexMap[sorted[j]];
                    ++cycles_count;
                }
                swaps += cycles_count - 1;
            }

            return swaps;
        };

    return min(findMinSwap(ascending), findMinSwap(descending));
}


int main() {
    return 0;
}
