#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int N;
enum
{
    MAX_IN = 100'000+1,
};
vector<vector<int>> order(2); //in,post

void DQ(vector<int> in, int p)
{
    if (p < 0 || in.size() <1) return;

    /*vector<int>& in = order[0];*/
    vector<int>& post = order[1];
    int root = post[p];
    
    cout << root << " "; //root

    auto r = ::find(in.begin(), in.end(), root);

    vector<int> left(in.begin(),r);
    vector<int> right(r+1,in.end());

    //left
    DQ(left, p - right.size() - 1);
    //right
    DQ(right, p - 1);
}

int main()
{
    FASTIO;
    cin >> N;
    
    for (int i = 0; i < 2; i++)
        order[i].resize(N);

    for(int j = 0; j < 2;j++)
        for (int i = 0; i < N; i++)
        {
            cin >> order[j][i];
        }
    DQ(order[0], N - 1);
    return 0;
}

#endif 

//struct Node
//{
//    Node(int k) : key(k){}
//    int key;
//    Node* left = nullptr;
//    Node* right = nullptr;
//};
//vector<Node*> nodes(MAX_IN, nullptr);
//const Node* NullNode = nodes[0];