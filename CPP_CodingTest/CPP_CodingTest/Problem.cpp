#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int N;
enum
{
    MAX_IN = 100'000 + 1,
};
struct Node
{
    Node(int k) : key(k){}
    int key;
    vector<Node*> adj;
};
vector<Node*> nodes(MAX_IN, nullptr);
vector<int> parents(MAX_IN);

void BFS(Node* root, int n)
{
    vector<bool> ck(n+1, false);
    queue<Node*> q;
    ck[root->key] = true;
    q.push(root);

    while (!q.empty())
    {
        Node* now = q.front();
        q.pop();

        for (Node* next : now->adj)
        {
            if (!ck[next->key])
            {
                ck[next->key] = true;
                q.push(next);
                parents[next->key] = now->key;
            }
        }
    }
}
int main()
{
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; i++) { nodes[i] = new Node(i); }
    //서로 adj에 넣기
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        nodes[u]->adj.push_back(nodes[v]);
        nodes[v]->adj.push_back(nodes[u]);
    }
    //1부터 Bfs등의 탐색
    BFS(nodes[1], N);
    //부모 출력
    for (int i = 2; i <= N; i++)
        cout << parents[i] << "\n";
    return 0;
}
#endif 

