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
<<<<<<< HEAD
    MAX_IN = 100'000+1,
=======
    MAX_IN = 1'0000 + 1,
>>>>>>> 9b048d62eb477ba119e36dcb737adf7533130fca
};
//struct Node
//{
//    Node(int k) : key(k){}
//    int key;
//    Node* left = nullptr;
//    Node* right = nullptr;
//};
//vector<Node*> nodes(MAX_IN, nullptr);
//const Node* NullNode = nodes[0];

vector<string> order(2); //in,post

void DQ(string in, int p)
{
<<<<<<< HEAD
    if (p < 0 || in.size() <1) return;

    /*string& in = order[0];*/
    string& post = order[1];
    char root = post[p];
    
    cout << root << " "; //root

    int r = in.find(root);
    string left = in.substr(0, r);
    string right = in.substr(r+1);

    //left
    DQ(left, p - right.size() - 1);
    //right
    DQ(right, p - 1);
=======
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
>>>>>>> 9b048d62eb477ba119e36dcb737adf7533130fca
}

int main()
{
    FASTIO;
    cin >> N;
    
    for (int i = 0; i < 2; i++)
        order[i].resize(N);

<<<<<<< HEAD
    for(int j = 0; j < 2;j++)
        for (int i = 0; i < N; i++)
        {
            cin >> order[j][i];
        }
    DQ(order[0], N - 1);
=======
    for (int i = 1; i < N; i++)
    {
        int u,v,d;
        cin >> u >> v >> d;
		nodes[u]->adj.push_back({ nodes[v], d });
		nodes[v]->adj.push_back({ nodes[u], d });
    }

    cout << DFS(DFS(nodes[1], N).first, N).second << "\n";
>>>>>>> 9b048d62eb477ba119e36dcb737adf7533130fca
    return 0;
}
//dd
#endif 

