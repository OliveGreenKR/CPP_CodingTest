#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;


int pairs(int k, vector<int> arr) {
    unordered_set<int> set;
    int count = 0;

    // 배열의 숫자들을 집합에 저장
    for (int num : arr)
    {
        set.insert(num);
    }

    // 배열을 순회하면서 차이가 k인 숫자쌍을 찾음
    for (int num : arr)
    {
        if (set.find(num + k) != set.end())
        {
            count++;
        }
    }

    return count;
}

int main() {

    return 0;
}