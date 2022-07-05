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
	Set(size_t size) : _size(size+1) {
		parent.resize(_size);
		//count.resize(_size);
		for (size_t i = 0; i < _size; i++)
		{
			parent[i] = i;
			//count[i] = 1;
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
			//count[b] += count[a];

		}
		else
		{
			parent[b] = a;
			//count[a] += count[b];
		}
	}
	bool IsSame(size_t a, size_t b) {
		return Find(a) == Find(b);
	}
	size_t GetSize() { return _size; }
	//size_t GetSetSize(size_t a) { return count[Find(a)]; }
private:
	size_t _size;
	vector<size_t> parent;
	//vector<size_t> count; //root [i]'s set size
};

int main() {
	FASTIO;
	
	return 0;
}

#endif 


                                                                                                                                                                                                                                                                                                                  