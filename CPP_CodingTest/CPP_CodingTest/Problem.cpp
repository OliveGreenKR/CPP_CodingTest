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
    MAX_IN = 100'000 + 1,
    INF = 10'0000
};
struct Node
{
    Node(int k) : key(k){}
    int key;
    vector<pair<Node*,int>> adj; //adj,dist
};
vector<Node*> nodes(MAX_IN, nullptr);

int Dijk(Node* now, int n)
{
    int maxret = 0;
    priority_queue<pair<int, Node*>> q;
    vector<int> dist(n + 1, INF);

    dist[now->key] = 0;
    q.push({ 0, now });

    while (!q.empty()) // 가장 최소 선택 후 거리 업데이트.
    {
        Node* now = q.top().second;
        q.pop();
        for (pair<Node*,int> next : now->adj)
        {
            if (dist[next.first->key] > dist[now->key] + next.second)
            {
                dist[next.first->key] = dist[now->key] + next.second;
                 q.push({ dist[next.first->key], next.first });
                maxret = ::max(maxret, dist[next.first->key]);
            }
        }
    }
    return maxret;
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

    int MaxD = 0;
    for (int i = 1; i <= N; i++)
    {
        MaxD = ::max(MaxD,Dijk(nodes[i], N));
    }
    cout << MaxD;
    return 0;
}
#endif 

