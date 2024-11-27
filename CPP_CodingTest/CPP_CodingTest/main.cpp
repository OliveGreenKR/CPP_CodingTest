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

using namespace std;
#define OUT

constexpr int MAXN = 1e5;

struct Node
{
    vector<int> children;
    bitset<MAXN> subTree;
};

bitset<MAXN> recordSubTree(int root, vector<Node*>& nodes)
{
    Node* now = nodes[root];
    now->subTree |= root;

    for (const int child : now->children)
    {
        Node* next = nodes[child];
        now->subTree |= recordSubTree(child, nodes);
    }

    return now->subTree;
    
}

string storyOfATree(const int n, const vector<vector<int>>& edges, const int k, const vector<vector<int>>& guesses) {

    vector<Node*> nodes(n);

    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new Node();
    }

    //build tree
    for (const auto& edge : edges)
    {
        nodes[edge[0] - 1]->children.push_back(edge[1] - 1); //0-based index
    }

    //record subtree except itself when [root == '0']
    recordSubTree(0, nodes);
    for (int i = 0; i < n ; i++)
    {
        Node* now = nodes[i];
        now->subTree.reset(i); 
    }
    
    vector<int> record(n, 0); //record the number possible guess when [root == i]

    //��� ��忡�� root = k �϶� �´� ������ �� record[k]�� ��� -> O(N*k)
    for (const auto& guess : guesses)
    {
        int parent = guess[0];  //u-v connection always guaranted.
        int child = guess[1];

        for (int r = 0; r < n; ++r)
        {
            //when root == r , guess is correct?
                //inversion when root is parent's subnode
            record[r] += nodes[parent]->subTree.test(r); 
        }
    }
    
    //count p
    int p = 0;
    int q = n;
    for (int result : record)
    {
        p += (result >= k);
    }

    int gcdPq = std::gcd(p, q);
    p /= gcdPq;
    q /= gcdPq;

    char buffer[50];
    sprintf(buffer, "%d/%d", p,q);
    return string(buffer);
}

int main() {
 ifstream fin("./input.txt"); // �Է� ���� ����
ofstream fout("./output.txt"); // ��� ���� ����
#pragma region OpenFile
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
    

   
#pragma region Close
    fin.close(); // �Է� ���� �ݱ�
    fout.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}