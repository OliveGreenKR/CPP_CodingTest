#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int N;
enum
{
    MAX_IN = 1'0000 + 1,
};
struct Node
{
    Node(int k) : key(k){}
    int key;
    vector<pair<Node*,int>> adj; //adj,dist
};
vector<Node*> nodes(MAX_IN);
pair<Node*, int> DFS(Node* st, int n) 
{
    stack<Node*> s;
    vector<bool> visited(n + 1, false);
    vector<int> dist(n+1, 0);
    int maxD = 0, idx = st->key;
    s.push(st);
    visited[st->key] = true;
    while (!s.empty())
    {
        Node* now = s.top();
        s.pop();
        for (auto next : now->adj)
        {
            Node* v = next.first;
            if (!visited[v->key])
            {
                s.push(v);
                visited[v->key] = true;
                dist[v->key] = dist[now->key] + next.second;
                if (dist[v->key] > maxD)
                {
                    maxD = dist[v->key];
                    idx = v->key;
                }
            }
        }
    }
    return { nodes[idx], maxD };
}

int main()
{
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; i++) nodes[i] = new Node(i);

    for (int i = 1; i < N; i++)
    {
        int u,v,d;
        cin >> u >> v >> d;
		nodes[u]->adj.push_back({ nodes[v], d });
		nodes[v]->adj.push_back({ nodes[u], d });
    }

    cout << DFS(DFS(nodes[1], N).first, N).second << "\n";
    return 0;
}
#endif 

