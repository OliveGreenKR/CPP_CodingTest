#include "pch.h"
#pragma warning(disable: 4996)

#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
enum
{
	MAX_IN = 100'000,
};
int N, T;

class Set
{
public:
	Set() {
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
	size_t _size= 200'000 + 1;
	vector<size_t> parent;
	vector<size_t> count; //root [i]'s set size
};

int main() {
	FASTIO;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		Set network;
		map<string, int> Hash;
		size_t idx = 0;
		for (int i = 0; i < N; i++)
		{
			string id1, id2;
			cin >> id1 >> id2;
			if (Hash.find(id1) == Hash.end())
			{
				Hash.emplace(id1, idx++);
			}
			if (Hash.find(id2) == Hash.end())
			{
				Hash.emplace(id2, idx++);
			}

			size_t a, b;
			a = Hash[id1];
			b = Hash[id2];
			if(!network.isSame(a,b))
				network.Merge(a, b);
			cout << network.getSetSize(b) << "\n";
		}
		
	}
	return 0;
}

#endif 


