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

    // �迭�� ���ڵ��� ���տ� ����
    for (int num : arr)
    {
        set.insert(num);
    }

    // �迭�� ��ȸ�ϸ鼭 ���̰� k�� ���ڽ��� ã��
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