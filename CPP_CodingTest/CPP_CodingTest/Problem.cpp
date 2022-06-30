#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum {
  MAX_IN = 1'000'000 + 1,
};
int N, M;

vector<int> parent(MAX_IN);

int Find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a > b) parent[a] = b;
    else
        parent[b] = a;
}

bool isSame(int a, int b) {
    return Find(a) == Find(b);
}

int main() {
  FASTIO;
  cin >> N >> M;
  for (int i = 0; i <= N; i++)
      parent[i] = i;

  for (int i = 0; i < M; i++) {
    int op, a, b;
    cin >> op >> a >> b;

    switch (op) {
      case 0:
        Union(a, b);
        break;
      case 1:
        if (isSame(a, b)) {
          cout << "YES\n";
        } else
          cout << "NO\n";
        break;
    }
  }

  return 0;
}

#endif 


