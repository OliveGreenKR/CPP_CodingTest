#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int N;
enum
{
    MAX_IN = 100'000 + 1,
};
struct Node
{
    Node(int k) : key(k)
    {}
    ~Node() {};

    int key = -1;
    Node* next = this;
    Node* parent = this;

};
vector<Node*> nodes(MAX_IN, nullptr);
vector<pair<int, int>> inputs(MAX_IN);
int main()
{
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; i++) { nodes[i] = new Node(i); }
    for (int i = 0; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v) ::swap(u, v);  //u<v
        inputs[i] = { u,v };
    }
    ::sort(inputs.begin(), inputs.end());

}


#endif 

