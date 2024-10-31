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

//잘못배치된 원소의 수를 타입별로 세야함
    //타입별로 수가 같으면, 컨테이너 관계없이 교환하여 처리 가능.
string organizingContainers(vector<vector<int>> container) {

    // Swap -> The total number of items in the containers does not change
        // ** Position changes are free.
        // In other words, each container already has space, so you just need to place the items according to their type.

    // If the pair of [each container's capacity] and [the number of items by type] matches, it is possible.

    const int n = container.size();


    vector<int> capacities(n, 0);
    vector<int> types(n, 0);

    //count capacity and types
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            capacities[i] += container[i][j];
            types[j] += container[i][j];
        }
    }

    ::sort(capacities.begin(), capacities.end());
    ::sort(types.begin(), types.end());

    if (::equal(capacities.begin(), capacities.end(), types.begin(), types.end()) == false)
    {
        return "Impossible";
    }

    return "Possible";
}

int main() {

    vector<vector<int>> container = { {0,2}, {1,1} };

    cout << organizingContainers(container) << endl;
    return 0;
}


