#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <iostream>
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

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

class Trie {

public:

	~Trie() {
		for (auto& it : _children) {
			delete it.second;
		}
	}

	void makeByKeys(vector<string>& keys) {

		auto it = keys.begin();
		Trie* now = this;

		while (it != keys.end()) {
			string key = *it;
			now->insertKey(key);

			now = now->_children.find(key)->second;
			it++;
		}
	}

	bool find(string& key) {
		return !(_children.find(key) == _children.end());
	}

	void PrintTrieDFS(string prefix) {
		for (auto it : _children) {
			cout << prefix << it.first << "\n";
			it.second->PrintTrieDFS(prefix+"--");
		}
	}

private:
	void insertKey(string key) {

		if (!find(key)) {
			_children.insert({key, new Trie()});
		}
	}

private:
	map<string, Trie*> _children;
};

int main() {
	FASTIO;
	int N;
	Trie* trie = new Trie();
	cin >> N;

	for (int i = 0; i< N; i++) {
		int k;
		cin >> k;
		vector<string> keys(k);
		for (auto& key : keys)
			cin >> key;

		trie->makeByKeys(keys);
	}

	trie->PrintTrieDFS("");
	
	return 0;
}
#endif 
