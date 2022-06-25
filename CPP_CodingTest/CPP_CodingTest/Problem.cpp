#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int> pre;
vector<int> post;

void getPost(vector<int>::iterator left, vector<int>::iterator right)
{
    if (right <= left) return;
    int root = *left;

    auto it = upper_bound(left+1, right, root);

    getPost(left + 1, it);
    getPost(it, right);
    post.push_back(root);
   
}

int main()
{
    FASTIO;
    int t;
    while (cin >> t)
        pre.push_back(t);
    getPost(pre.begin(), pre.end());
  
    for (int c : post)
        cout << c << "\n";
    return 0;
}

#endif 


