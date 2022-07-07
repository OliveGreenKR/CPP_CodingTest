#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_N = 100'000+1,
	MAX_M = 100'000+1, 
};
int N;

class Set
{
public:
	Set(size_t size) : _size(size + 1) {
		parent.resize(_size);

		for (size_t i = 0; i < _size; i++)
		{
			parent[i] = i;
		}
	}
	int Find(size_t a) {
		if (parent[a] == a)
			return a;
		return parent[a] = Find(parent[a]);
	}
	void Merge(size_t a, size_t b) {
		a = Find(a);
		b = Find(b);
		if (a > b)
		{
			parent[a] = b;
		}
		else
		{
			parent[b] = a;
		}
	}
	bool IsSame(size_t a, size_t b) {
		return Find(a) == Find(b);
	}
	size_t GetSize() { return _size; }
private:
	size_t _size;
	vector<size_t> parent;
};
enum
{
	Z,
	Y,
	X,
};
vector<vector<pair<int, int>>> coord(3); //[plane][val][idx]
vector<pair<int, pair<int, int>>> edges; // [cost][[idx1,idx2]]

inline int getCost(int plane, int idx) {
	return coord[plane][idx].first - coord[plane][idx + 1].first;
}

auto getEdge(int plane, int idx) {
	return
		make_pair(::abs(getCost(plane, idx)), make_pair( coord[plane][idx].second,coord[plane][idx + 1].second ));
}
int main() {
	FASTIO;
	cin >> N;
	Set s(N);
	for (int i = Z; i <= X; i++)
	{
		coord[i].reserve(N);
	}
	edges.reserve(3*N);

	for (int idx = 1; idx <= N; idx++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		coord[Z].push_back({ z,idx });
		coord[Y].push_back({ y,idx });
		coord[X].push_back({ x,idx });
	}

	::sort(coord[Z].begin(), coord[Z].end());
	::sort(coord[Y].begin(), coord[Y].end());
	::sort(coord[X].begin(), coord[X].end());

	for (int i = 0; i < N-1; i++)
	{
		edges.push_back(getEdge(Z, i));
		edges.push_back(getEdge(X, i));
		edges.push_back(getEdge(Y, i));
	}

	::sort(edges.begin(), edges.end());
	size_t ret = 0;

	for (auto e :  edges)
	{
		int idx1, idx2;
		idx1 = e.second.first;
		idx2 = e.second.second;
		if (!s.IsSame(idx1, idx2))
		{
			s.Merge(idx1, idx2);
			ret += e.first;
		}
	}

	cout << ret << "\n";
	return 0;
}
#endif 
                                                                                                                                                                                                                                                                                                   