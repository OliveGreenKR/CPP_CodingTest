#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_N = 1'000+1,
	MAX_M = 10'000+1, 
};
int N, M;

class Set
{
public:
	Set(size_t size) : _size(size+1) {
		parent.resize(_size);
		count.resize(_size);
		for (size_t i = 0; i < _size; i++)
		{
			parent[i] = i;
			count[i] = 1;
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
			count[b] += count[a];

		}
		else
		{
			parent[b] = a;
			count[a] += count[b];
		}
	}
	bool isSame(size_t a, size_t b) {
		return Find(a) == Find(b);
	}
	size_t getSize() { return _size; }
	size_t getSetSize(size_t a) { return count[Find(a)]; }
private:
	size_t _size;
	vector<size_t> parent;
	vector<size_t> count; //root [i]'s set size
};

vector<pair<int, int>> edges(MAX_M);

int getAns() {
	int ret = 0;
	Set s(N);
	for (int i =1;i<=M;i++)
	{
		auto& e = edges[i];
		if (!s.isSame(e.first, e.second))
		{
			s.Merge(e.first, e.second);
			ret++;
		}
	}
	return ret;
}
int main() {
	FASTIO;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		for (int i = 1; i <= M; i++) //inputs
		{
			cin >> edges[i].first >> edges[i].second;
		}

		cout << getAns() << "\n";
	}
	return 0;
}

#endif 


                                                                                                                                                                                                                                                                                                                  