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
#include <fstream> // 파일 입출력을 위한 헤더 추가
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>

#define OUT

using namespace std;

struct Node
{
    int x, y;
    Node* left;
    Node* right;

    Node(int x_, int y_) : x(x_), y(y_), left(nullptr), right(nullptr) {}
};

inline long long CoordHash (int x, int y)
{
    return x + y * 1e6;
};

using NodeMap = unordered_map<long long, int>;

// Helper function to insert a node into the tree
Node* insertNode(Node* root, Node* newNode) {
    // empty tree
    if (!root) 
        return newNode;

    //parent of root
    if (newNode->y > root->y)
    {
        // Determine if current root should be left or right child
        if (root->x < newNode->x)
        {
            newNode->left = root;
        }
        else
        {
            newNode->right = root;
        }
        return newNode;
    }

    // child of root
    if (newNode->x < root->x)
    {
        // Insert into left subtree
        root->left = insertNode(root->left, newNode);
    }
    else if (newNode->x > root->x)
    {
        // Insert into right subtree
        root->right = insertNode(root->right, newNode);
    }

    return root;
}

Node* constructBinaryTree(const vector<vector<int>>& nodeInfo) {
    
    // Sort nodes by y-coordinate (level) in descending order
    vector<vector<int>> sortedNodes = nodeInfo;
    sort(sortedNodes.begin(), sortedNodes.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] > b[1];  // Sort by y-coordinate
         });

    Node* root = nullptr;

    // Process each node and insert it into the tree
    for (const auto& node : sortedNodes)
    {
        Node* newNode = new Node(node[0], node[1]);
        root = insertNode(root, newNode);
    }

    return root;
}


void preOrder(const Node* root, vector<int>& record, const NodeMap& nodeMap)
{
    if (root == nullptr)
        return;

    long long coord = CoordHash(root->x, root->y);

    record.push_back(nodeMap.at(coord));
    preOrder(root->left, record, nodeMap);
    preOrder(root->right, record, nodeMap);
}

void postOrder(const Node* root, vector<int>& record, const NodeMap& nodeMap)
{
    if (root == nullptr)
        return;

    preOrder(root->left, record, nodeMap);
    preOrder(root->right, record, nodeMap);
    long long coord = CoordHash(root->x, root->y);
    record.push_back(nodeMap.at(coord));
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    const int n = nodeinfo.size();

    NodeMap nodeMap; //nodeMap [coord][nodeidx]
    for (int i = 0; i < n; ++i)
    {
        const auto& node = nodeinfo[i];
        long long coord = CoordHash(node[0], node[1]);
        nodeMap[coord] = i+1;
    }


    //buildTree
    Node* root = constructBinaryTree(nodeinfo);


    vector<vector<int>> answer(2);

    preOrder(root, answer[0], nodeMap);
    postOrder(root, answer[1], nodeMap);

    return answer;
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
        return 1; // 입력 파일을 열 수 없으면 프로그램 종료
    }
    if (!fout)
    {
        cerr << "Unable to open output file";
        return 1; // 출력 파일을 열 수 없으면 프로그램 종료
    }
#pragma endregion

    vector<vector<int>> nodeinfo = {{ 5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, { 6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 }, { 2, 2 }};
    solution(nodeinfo);
#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}