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
#include <numeric> //gcd
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>


#define OUT

using namespace std;

const int INF = 1e9;

//m������ ũ��� ����� �ִ� �ּ� �׷��� ���� , ���� main-�׷��� ũ��
pair<int, int> findMinGroups(const int m, const int now, const int parent, const vector<vector<int>>& adj, const vector<int>& nodeinfo)
{
    //ũ�Ⱑ ū ������� -> maxHeap ���
    priority_queue<int> subHeap;

    int sum = nodeinfo[now];

    if (sum > m)
        return { INF,INF };

    int groups = 1;

    //dfs Ž������ subTree�� ��
    for (auto next : adj[now])
    {
        if (next == parent)
            continue;
        auto [gcount, subSum] = findMinGroups(m, next, now, adj, nodeinfo);

        if (gcount == INF)
            return { INF,INF };

        sum += subSum;
        groups += gcount - 1;
        subHeap.push(subSum);
    }

    //divide groups
    while (!subHeap.empty() && sum > m)
    {
        ++groups;
        sum -= subHeap.top(); //biggest subTree
        subHeap.pop();
    }
    return { groups, sum }; //return cuurent TreeSum
}



//�׷� ���� k�϶� ���� ū ������ �ּ� ũ�� ��ȯ
int binarySearch(int k, const vector<int>& nodeinfo, const vector<vector<int>>& adj)
{
    //root = 0
    //������ ũ�� ���� [1..all]
    int left = 1;
    int right = 1e8;
    int mid = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        //���� ū ������ ũ�Ⱑ mid �����϶��� �׷� ����
        auto [gcount, sums] = findMinGroups(mid, 0, -1, adj, nodeinfo);

        //k �ʰ��� �׷� ���� ���� -> ���� ũ�� ����
        if (gcount > k)
            left = mid + 1;

        //k ������ �׷� ���� ���� -> ���� ũ�� ����
        if (gcount <= k)
            right = mid; //mid���� �����ؾ� ��
    }

    return right;
}


int solution(int k, vector<int> num, vector<vector<int>> links) {

    const int n = num.size();

    vector<vector<int>> adj(n);
    //build bidirectional adj[i]
    for (int i = 0; i < n; ++i)
    {
        const auto link = links[i];

        if (link[0] >= 0)
        {
            adj[i].push_back(link[0]);
            adj[link[0]].push_back(i);
        }
        if (link[1] >= 0)
        {
            adj[i].push_back(link[1]);
            adj[link[1]].push_back(i);
        }
    }

    return binarySearch(k, num, adj);
}

int main() {
    string infile = "./input.txt";
    string outfile = "./output.txt";
#pragma region OpenFile
    ifstream fin(infile);
    ofstream fout(outfile);
    if (!fin)
    {
        cerr << "Unable to open input file";
        return 1; // �Է� ������ �� �� ������ ���α׷� ����
    }
    if (!fout)
    {
        cerr << "Unable to open output file";
        return 1; // ��� ������ �� �� ������ ���α׷� ����
    }
#pragma endregion
    int k = 4;
    vector<int> num = { 6, 9, 7, 5 };
    vector<vector<int>> links = { {-1, -1}, { -1, -1 }, { -1, 0 }, { 2, 1 } };
    cout << solution(k, num,links);

#pragma region CloseFile 
    fin.close(); // �Է� ���� �ݱ�
    fout.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}