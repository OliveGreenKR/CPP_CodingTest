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

class Trie {

public:

	Trie(int64 cnt = 0)  : _cnt(cnt) {
		_children.resize(26,nullptr);
	}
	~Trie() {
		for (auto tr : _children) {
			if( tr != nullptr)
				delete tr;
		}
	}

	void insert(char* c) {
		if (*c == NULL) {
			_flag = true;
			return;
		}
		int idx = *c - 'a';
		if (_children[idx] == nullptr) {
			_children[idx] = new Trie();
			_cnt++;
		}

		_children[idx]->insert(c+1);
	}

	bool find(char* c) {
		if (*c == NULL)
			return true;

		int idx = *c - 'a';
		Trie* now = _children[idx];

		if (now == nullptr)
			return false;

		return now->find(c+1);
	}

	void printTrie(string prefix) {
		for (int i = 0; i < 26; i++) {
			Trie* now = _children[i];
			if (now !=nullptr) {
				char c = i+'a';
				cout << c << " " << now->_pcnt <<  "\n";
				now->printTrie(prefix+"-");
			}
		}
	}

	int64 getPcnt() {
		int64 ret = 0;
		for (auto tr : _children) {
			if (tr != nullptr) {
				tr->_pcnt = 1;
				ret += tr->Pcnt();
			}
		}
		return ret;
	}

	int64 Pcnt() {

		int64 ret = 0;

		if (_cnt== 0 && _flag)
			return _pcnt;

		for (auto tr : _children) {
			if (tr != nullptr) {

				if(_cnt > 1 || _flag)
					tr->_pcnt = _pcnt+1;
				else
					tr->_pcnt = _pcnt;

				/*if (_flag)
					tr->_pcnt++;*/
				ret += tr->Pcnt();
			}
		}

		if (_flag)
			ret += _pcnt;
		return ret;
	}

private:
	vector<Trie*> _children;
	bool _flag = false;
	int64 _cnt = 0; //children cnt
public:
	int64 _pcnt = 0; //input cnt
};

int main() {
	FASTIO;
	int N;
	while (cin >> N) {
		Trie* trie = new Trie();
		for (int i = 0; i < N; i++) {
			char str[81];
			cin >> str;
			trie->insert(str);
		}
		int64 ret = trie->getPcnt();
		//trie->printTrie("");
	
		cout << setprecision(2) << fixed <<  ret / (double)N << "\n";
		delete trie;
	}

	return 0;
}
#endif 
