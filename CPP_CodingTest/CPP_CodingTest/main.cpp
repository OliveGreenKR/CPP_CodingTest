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

const int INF = 1e5;
const int NONE = 1e4;


int recordSunSUM(int now, int parent, const vector<int>& num, const vector<vector<int>>& adj, vector<int>& record)
{
    const int n = num.size();

    if (now < 0 || now >= n)
        return 0;

    int result = num[now];

    for (const int next : adj[now])
    {
        if (next == parent)
            continue;
        result += recordSunSUM(next, now, num, adj, record);
    }

    //record
    record[now] = result;
    return result;
}


//�ִ� ũ�Ⱑ m������ �׷��� �ּ� ����
int findMinGroups(int m, int root, int parent,  const vector<int>& accum, const  vector<vector<int>>& adj)
{
    if (root == NONE)
        return 0;

    int gcount = 1; //�⺻ �׷� �� 

    //m������ ����Ʈ��
    if (accum[root] <= m)
        return gcount;

    //find next child..
    vector<int> childs;
    for (const int next : adj[root])
    {
        if (next != parent)
            childs.push_back(next);
    }
    int left = childs[0];
    int right = childs[1];
    /* Case 1 : �� �� �и��ص� �Ұ� -> 'm�� �ʹ� �۴�'  ->
       ����Ž�� �� 'k���� ���� �׷�'�� ���;� m�� ������Ŵ*/
    if (accum[root] - accum[left] - accum[right] > m)
        return INF;

    /*Case 2 : �ڽ� �ϳ� �и� */
    //�� �� ������ ���� �ִٸ� �ִ��� ���� �������� �������Ѿ���
    if (accum[root] - accum[left] <= m || accum[root] - accum[right] <= m)
    {

        if (accum[right] > accum[left])
        {
            //left is smaller
            gcount += findMinGroups(m, left, root, accum, adj);
        }
        else
        {
            gcount += findMinGroups(m, right, root, accum, adj);
        }
    }
    else
    {
        /*Case 3 : �� �� �и��ؾ� ����*/
        gcount += findMinGroups(m, left,root, accum, adj)
            + findMinGroups(m, right,root, accum, adj);
    }


    //�ִ� INF�� ���� �ʵ��� ��� ����.
    return min(INF, gcount);
}


//�׷� ���� k�϶� ���� ū ������ �ּ� ũ�� ��ȯ
int binarySearch(int k, const vector<int>& record, const vector<vector<int>>& adj)
{
    //root = 0
    //������ ũ�� ���� [1..all]
    int left = 1;
    int right = record[0]; //root = 0
    int mid = 0;
    int gcount = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        //���� ū ������ ũ�Ⱑ mid �����϶��� �׷� ����
        gcount = findMinGroups(mid, 0, -1, record, adj);

        //k �ʰ��� �׷� ���� ���� -> ���� ũ�� ����
        if (gcount > k)
            left = mid + 1;

        //k ������ �׷� ���� ���� -> ���� ũ�� ����
        if (gcount <= k)
            right = mid; //mid���� �����ؾ� ��
    }

    return mid;
}


int solution(int k, vector<int> num, vector<vector<int>> links) {

    const int n = num.size();

    vector<vector<int>> adj(n);
    //build bidirectional adj[i]
    for (int i = 0; i < n ; ++i)
    {
        const auto link = links[i];

        adj[i].push_back(link[0]);
        adj[i].push_back(link[1]);

        adj[link[0]].push_back(i);
        adj[link[1]].push_back(i);
    }

    vector<int> record(NONE+1); //record accumulation
    recordSunSUM(0, -1,num, adj, record);

    return binarySearch(k, record, links);
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
    vector<int> num = { 12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1 };
    vector<vector<int>> links = { {-1, -1}, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 8, 5 }, { 2, 10 }, { 3, 0 }, { 6, 1 }, { 11, -1 }, { 7, 4 }, { -1, -1 }, { -1, -1 } };
    int k = 3;
    cout << solution(3, num,links);

#pragma region CloseFile 
    fin.close(); // �Է� ���� �ݱ�
    fout.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}