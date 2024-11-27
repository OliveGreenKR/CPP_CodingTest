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
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>

#define OUT

using namespace std;

struct Node
{
    int value = 1;  //the number of nodes in tree

    vector<Node*> children;
};

int solution(Node* root, OUT int& count)
{
    for (Node* child : root->children)
    {
        root->value += solution(child,count);
    }
    count += (root->value % 2 == 0);
    return root->value;
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {

    vector<Node*> tree(t_nodes);

    for (int i = 0; i < t_nodes; ++i)
    {
        tree[i] = new Node();
    }


    for (int i = 0; i < t_edges; ++i)
    {
        int child = t_from[i] - 1; //zero-based
        int parent = t_to[i] - 1;
        tree[parent]->children.push_back(tree[child]);
    }
    
    int cnt = -1;
    solution(tree[0], cnt);
    return cnt;
}


int main() {
 ifstream inputFile("./input.txt"); // �Է� ���� ����
ofstream outputFile("./output.txt"); // ��� ���� ����
#pragma region OpenFile
    if (!inputFile)
    {
        cerr << "Unable to open input file";
        return 1; // �Է� ������ �� �� ������ ���α׷� ����
    }
    if (!outputFile)
    {
        cerr << "Unable to open output file";
        return 1; // ��� ������ �� �� ������ ���α׷� ����
    }
#pragma endregion

    vector<int> from = {2,3,4,5,6,7,8,9,10};
    vector<int> to = {1,1,3,2,1,2,6,8,8};
    cout << evenForest(10, 9, from, to);
   
#pragma region Close
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}