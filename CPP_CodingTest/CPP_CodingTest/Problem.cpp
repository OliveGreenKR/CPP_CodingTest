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

using namespace std;
using int64 = long long;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

struct Node {
	vector<int> adj;
};


void TopologySort(vector<Node>& nodes,vector<int>& indegree, vector<int>& result) {

	int maxN = nodes.size(); //node max count
	queue<int> q;
	result.resize(maxN);

	//push zero indgree node to Q

	for (int now = 0; now < maxN; now++) {

		if (indegree[now]==0) {
			q.push(now);
		}
	}

	if (q.size()>1) {
		cout << "?\n";
		return;
	}

	//topology sort
	for (int now = 0; now < maxN; now++) {
		if (q.empty()) {
			cout << "IMPOSSIBLE\n";
			return; //cyclic graph
		}

		int next = q.front();
		q.pop();

		result[now] = next;

		//push zero indgree node to Q
		for (auto n : nodes[next].adj) {
			if (--indegree[n] == 0)
				q.push(n);
		}

		if (q.size()>1) {
			cout << "?\n";
			return;
		}
	}

	for (auto& out : result)
		cout << (out+1) << " ";
	cout << "\n";

	return;
}


void makeIndegree(auto& matrix, auto& ranks) {
	int indeg = 0;
	for (auto& r : ranks) {
		matrix[r-1] = indeg++;
	}
	return;
}

void makeNodes(auto& nodes, auto& ranks) {
	for (int rank = 0; rank < ranks.size(); rank++) {
		auto& node = ranks[rank];
		for (int r = rank+1; r < ranks.size(); r++) {
			auto& tonode = ranks[r];
			nodes[node-1].adj.push_back(tonode-1);
		}
	}
}

int main() {
	FASTIO;
	int T, N, M;
	cin >> T;

	for (int i = 0; i<T; i++) {
		cin >> N;
		vector<int> preranks(N);
		for (auto& r : preranks)
			cin >> r;
		vector<int> indegrees(N);
		vector<Node> nodes(N);
		makeIndegree(indegrees, preranks);
		makeNodes(nodes, preranks);

		cin >> M;
		for (int j = 0; j<M; j++) {
			int A, B;
			cin >> A >> B;
			indegrees[--A]--;
			indegrees[--B]++;
		}

		vector<int> result(N);

		TopologySort(nodes, indegrees, result);

	}

	return 0;
}
#endif 
