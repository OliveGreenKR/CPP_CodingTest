#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

using int64 = long long;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)

/*-----------------------
	String
-------------------------*/

namespace MySTR
{
	inline int Ctoi(char ch);
	inline int Stoi(const string& nstr);
	inline string Itos(int n);
	string Mul(string s1, string s2);
	string Sum(string s1, string s2);
	vector<string> Delim(string&& str, string& delim);
} 

/*----------------------
		Cin
-----------------------*/
struct MyCIN : std::ctype<char>
{
	MyCIN() : std::ctype<char>(get_table()) {}
	static mask const* get_table()
	{
		static mask rc[table_size];
		rc['.'] = std::ctype_base::space;
		rc['\n'] = std::ctype_base::space;
		return &rc[0];
	}
};
//cin.imbue(locale(cin.getloc(), new MyCIN));

/*---------------------------------
	DisJointSet (Union-FInd)
-----------------------------------*/

class DisJointSet
{
public:
	DisJointSet(int N) : _size(N) {
		_parent.resize(_size);
		_count.resize(_size);
		for (size_t i = 0; i < _size; i++)
		{
			_parent[i] = i;
			_count[i] = 1;
		}
		_setcnt = N;
	}
	size_t Find(size_t a) {
		if (_parent[a] == a)
			return a;
		return _parent[a] = Find(_parent[a]);
	}
	void Merge(size_t a, size_t b) {
		a = Find(a);
		b = Find(b);
		if (a > b) //작은수를 기준으로 병합
		{
			_parent[a] = b;
			_count[b] += _count[a];
		}
		else
		{
			_parent[b] = a;
			_count[a] += _count[b];
		}
		_setcnt--;
	}
	bool isSame(size_t a, size_t b) {
		return Find(a) == Find(b);
	}

	size_t getSize() { return _size; }
	size_t getSetSize(size_t a) { return _count[Find(a)]; }
	size_t getSetCnt() { return _setcnt; }
	size_t getMaxSetSize() {
		size_t maxcnt = 0;
		for (auto& cnt : _count)
			maxcnt = ::max(cnt, maxcnt);
		return maxcnt;
	}
	
private:
	size_t _size;
	vector<size_t> _parent;
	vector<size_t> _count; //root [i]'s set size
	size_t _setcnt;
};

/***********************
		Bitset
***********************/
namespace myBitset {
	int add(int mask, int x) {
		mask |= (1 << x);
		return mask;
	}
	int remove(int mask, int x) {
		mask &= (~(1 << x));
		return mask;
	}
	bool check(const int& mask, int x) {
		return mask & (1 << x) ? 1 : 0;
	}

	int countBit(int mask) {
		int cnt = 0;
		while (mask) {
			cnt += (mask & 1);
			mask >>= 1;
		}
		return cnt;
	}

	int getAll(int x) {
		return (1<<(x))-1;
	}
}

/***********************
		MyMath
***********************/
namespace mmath {

	enum {
		Yet = -1,
	};

	template <typename T>
	T Combination(int n, int k, T** dp, const int MOD) {
		if (n<1 || k<0 || n<k)
			return 0;
		if (k==1)
			return n;
		if (k==0)
			return 1;

		T& ret = dp[n][k];

		if (ret != Yet)
			return ret;
		return ret = (Combination(n-1, k, dp, MOD) + Combination(n-1, k-1, dp, MOD)) % MOD;
	}

}