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
    int data;
    Node* left = nullptr;
    Node* right =  nullptr;
    Node(int d) : data(d) {};
    //Node(int x_, int y_) : x(x_), y(y_), left(nullptr), right(nullptr) {}
};



using NodeMap = unordered_map<long long, int >;

inline long long CoordHash(int x, int y)
{
    return x + y * 1e6;
}

Node* buildTree(const vector<vector<int>>::iterator& start, const vector<vector<int>>::iterator& end, NodeMap& nodemap)
{
    if (start > end)
        return nullptr;

    //find max y
    auto rootIt = max_element(start, end, [](const vector<int>& A, const vector<int>& B) {return A[1] > B[1]; });

    int nodeIdx = nodemap[CoordHash(rootIt->at(0), rootIt->at(1))];
    Node* root = new Node(nodeIdx);
    root->left = buildTree(start, rootIt, nodemap);
    root->right = buildTree(rootIt+1, end, nodemap);

    return root;
}

void preOrder(const Node* root, vector<int>& record)
{
    if (root == nullptr)
        return;

    record.push_back(root->data);
    preOrder(root->left, record);
    preOrder(root->right, record);
}

void postOrder(const Node* root, vector<int>& record)
{
    if (root == nullptr)
        return;
    postOrder(root->left, record);
    postOrder(root->right, record);
    record.push_back(root->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    const int n = nodeinfo.size();

    //build NodeMap
    NodeMap nodeMap; //nodeMap [coord][nodeidx]
    for (int i = 0; i < n; ++i)
    {
        const auto& node = nodeinfo[i];
        long long coord = CoordHash(node[0], node[1]);
        nodeMap[coord] = i + 1;
    }

    auto it =  nodeinfo.begin();

    //sort with x
    sort(nodeinfo.begin(), nodeinfo.end(),[](const vector<int>& A, const vector<int>& B)
         {
             return A[0] < B[0]; //x-ascending order
         });


    //buildTree
    Node* root = buildTree(nodeinfo.begin(), nodeinfo.end(), nodeMap);

    vector<vector<int>> answer(2);
    
    //preorder
    preOrder(root, answer[0]);
    //postorder
    postOrder(root, answer[0]);

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