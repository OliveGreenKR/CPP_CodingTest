#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_N = 1'0000+1,
	MAX_M = 100'000+1, 
};
int N, M;

class Set
{
public:
	Set(long long size) : _size(size+1) {
		parent.resize(_size);
		count.resize(_size);
		for (long long i = 0; i < _size; i++)
		{
			parent[i] = i;
			count[i] = 1;
		}
	}
	int Find(long long a) {
		if (parent[a] == a)
			return a;
		return parent[a] = Find(parent[a]);
	}
	void Merge(long long a, long long b) {
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
	bool IsSame(long long a, long long b) {
		return Find(a) == Find(b);
	}
	long long GetSize() { return _size; }
	long long GetSetSize(long long a) { return count[Find(a)]; }
private:
	long long _size;
	vector<long long> parent;
	vector<long long> count; //root [i]'s set size
};
struct Edge
{
	int cost; int u; int v;
};
const bool operator>(const Edge& left, const Edge& right) {

	return left.cost > right.cost;
}

vector<Edge> edges(MAX_M);

long long getAns() {
	long long ret = 0;
	priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
	Set s(N);

	for (int i = 1; i <= M; i++)
		pq.push(edges[i]);

	//Greedy
	
	while (!pq.empty())
	{
		auto& e = pq.top();
		if (!s.IsSame(e.u, e.v))
		{
			s.Merge(e.u, e.v);
			ret += e.cost;
		}
		pq.pop();
	}
	return ret;
}
int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = Edge{ c,a,b };
	}
	cout << getAns() << "\n";
	return 0;
}

#endif 


                                                                                                                                                                                                                                                                                                                  