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
    MAX_IN = 100'000 + 1,
};
struct Node
{
    Node(int k) : key(k){}
    int key;
    vector<pair<Node*,int>> adj; //adj,dist
};
vector<Node*> nodes(MAX_IN);
pair<Node*, int> DFS(Node* st, int n) //최장경로의 노드를 리턴
{
    stack<Node*> s;
    vector<bool> visited(n + 1, false);
    vector<int> dist(MAX_IN, 0);
    int maxD = 0, idx = 0;
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

    for (int i = 0; i < N; i++)
    {
        int st; cin >> st;
        while (true)
        {
            int v;
            cin >> v;
            if (v < 0) break;
            int d;
            cin >> d;
            nodes[st]->adj.push_back({nodes[v], d});
        }
    }

    cout << DFS(DFS(nodes[1], N).first, N).second << "\n";
    return 0;
}
#endif 

