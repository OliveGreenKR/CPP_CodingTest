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

using namespace std;
#define OUT

constexpr int MAXN = 1e5;

struct Node
{
    vector<int> children;
    bitset<MAXN> subTree;
};

bitset<MAXN> recordSubTree(int root, vector<Node*>& nodes)
{
    Node* now = nodes[root];
    now->subTree.set(root);

    for (const int child : now->children)
    {
        now->subTree |= recordSubTree(child, nodes);
    }
    int cnt = now->subTree.count();
    return now->subTree;
    
}

void buildTreewithDAG(int root, vector<Node*> nodes, const vector<vector<int>>& adj)
{
    Node* now = nodes[root];
    for (const int child : adj[root])
    {
        now->children.push_back(child);
        buildTreewithDAG(child, nodes, adj);
    }
}

string storyOfATree(const int n, const vector<vector<int>>& edges, const int k, const vector<vector<int>>& guesses) {

    vector<vector<int>> adj(n);

    //build dag
    for (const auto& edge : edges)
    {
        adj[edge[0] - 1].push_back(edge[1] - 1);
        adj[edge[1] - 1].push_back(edge[0] - 1);
    }




    //build tree
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new Node();
    }

    buildTreewithDAG(edges[0][0] - 1, nodes, adj);
    recordSubTree(edges[0][0]-1, nodes);
    //for (int i = 0; i < n ; i++)
    //{
    //    Node* now = nodes[i];
    //    now->subTree.reset(i); 
    //}
    
    const int g = guesses.size();
    vector<int> record(n,g); //record the number possible guess when [root == i]

    //Number of predictions correct when root = k on all nodes write to record[k] -> O(N*k)
    for (const auto& guess : guesses)
    {
        int parent = guess[0]-1;  //u-v connection always guaranted.
        int child = guess[1]-1;

        for (int r = 0; r < n; ++r)
        {
            if (r == parent) continue;
            //The new route belongs to parent's sub And
                // parent's child belongs to the new root's subtree -> inversion
            int inversion =
                nodes[parent]->subTree.test(r) && nodes[r]->subTree.test(child);
            record[r] -= inversion;
        }
    }
    
    //count p
    int p = 0;
    int q = n;
    for (int result : record)
    {
        p += (result >= k);
    }

    int gcdPq = std::gcd(p, q);
    p /= gcdPq;
    q /= gcdPq;

    char buffer[50];
    sprintf_s(buffer, "%d/%d", p,q);
    return string(buffer);
}

int main() {
	ifstream fin("./input.txt"); // 입력 파일 열기
	ofstream fout("./output.txt"); // 출력 파일 열기
#pragma region OpenFile
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
    
    int q;
    fin >> q;

    for (int i = 0; i < q; ++i)
    {
        int n;
        

        fin >> n;
        vector<vector<int>> edges(n - 1, vector<int>(2));
        for (int j = 0; j < n-1; ++j)
        {
            fin >> edges[j][0] >> edges[j][1];
        }

        int g, k;
        fin >> g >> k;
        vector<vector<int>> guesses(g, vector<int>(2));
        for (int k = 0; k < g; ++k)
        {
            fin >> guesses[k][0] >> guesses[k][1];
        }
        

        cout << storyOfATree(n, edges, k, guesses) << "\n";
    }
   

    /*
    19/50
    1/1
    217/250
    0/1
    67/1000
*/
#pragma region Close
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}