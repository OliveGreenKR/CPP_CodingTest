#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int N;
enum
{
    MAX_IN = 100'000+1,
};
vector<vector<int>> order(2); //in,post,pre

void DivQ(int left, int right, int p) {
    if (left > right || p<0) return;
    
    vector<int>& post = order[1];
    vector<int>& in = order[0];
    int root = post[p];
  
    cout << root << " "; //root

    auto r = ::find(in.begin() + left, in.begin() + right + 1, root);
    
    int llen = r - in.begin() - left;
    int rlen = in.begin() + right - r;
    int ridx = r - in.begin();

    DivQ(left,ridx-1, p-rlen-1);
    DivQ(ridx+1,ridx+rlen,p-1);
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
    DivQ(0, N - 1,N-1);
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