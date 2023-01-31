#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <limits.h>

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
using int64 = long long;

template<typename Ty>
using minHeap = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Node {
	vector<int> _adj;
};

void HeapTopologySort(vector<Node>& nodes, vector<int>& indegree, vector<int>& result) {

	minHeap<int> pq; //min Heap

	const int N = indegree.size();
	
	result.resize(N);

	for (int i = 0; i < N; i++) {
		if (indegree[i]==0) {
			pq.push(i);
		}
	}

	for (int i = 0; i < N; i++) {

		if (pq.empty())
			return;
		int now = pq.top();
		pq.pop();

		result[i] = now;

		for (auto& n : nodes[now]._adj) {
			if (--indegree[n] == 0){
				pq.push(n);
			}
		}
	}

	return;
}


int main() {
	FASTIO;
	int N,M;
	cin >> N >> M;

	vector<int> indegrees(N);
	vector<Node> nodes(N);
	vector<int> result;

	for (int i = 0; i< M; i++) {
		int A, B;
		cin >> A >> B;
		indegrees[--B]++;
		nodes[--A]._adj.push_back(B);
	}

	HeapTopologySort(nodes, indegrees, result);

	for (int& n : result)
		cout << ++n << " ";

	return 0;
}
#endif 
