#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
using int64 = long long;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

struct Pos {
	int64 x = 0;
	int64 y = 0;
};

struct Line {
	Pos p1;
	Pos p2;
};

enum : int64 {
	MAX_X =  5000,
};
bool operator==(Pos& A, Pos& B) {
	return A.x == B.x && A.y == B.y;
}
bool operator!=(Pos& A, Pos& B) {
	return !(A==B);
}

double CCW(Pos& p1, Pos& p2, Pos& p3) {
	double ccw = (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
	if (ccw == 0)
		return 0; //onLine
	else
		return ccw > 0 ? 1 : -1;
}
bool IsMiddleX(Pos& p1, Pos& p2, Pos& p3) {
	return (::min(p1.x, p2.x) <= p3.x) && (p3.x <= ::max(p1.x, p2.x));
}
bool IsMiddleY(Pos& p1, Pos& p2, Pos& p3) {
	return (::min(p1.y, p2.y) <= p3.y) && (p3.y <= ::max(p1.y, p2.y));
}

bool IsMiddleP(Pos& p1, Pos& p2, Pos& p3) {
	return IsMiddleX(p1, p2, p3) && IsMiddleY(p1, p2, p3);
}

bool CheckCCW(Line& l1, Line& l2) {
	Pos p1 = l1.p1;
	Pos p2 = l1.p2;

	Pos p3 = l2.p1;
	Pos p4 = l2.p2;

	int a = CCW(p1, p2, p3);
	int b = CCW(p1, p2, p4);
	
	int c = CCW(p3, p4, p1);
	int d = CCW(p3, p4, p2);

	if (a*b < 0  && c*d < 0)
		return 1;

	if (a == 0 || b == 0)
		if ((a == 0 && IsMiddleX(p1, p2, p3) && IsMiddleY(p1, p2, p3)) ||
			(b==0 && IsMiddleX(p1, p2, p4) && IsMiddleY(p1, p2, p4)))
			return 1;

	if (c == 0 || d == 0)
		if ((c == 0 && IsMiddleX(p3, p4, p1) && IsMiddleY(p3, p4, p1)) ||
			(d == 0 && IsMiddleX(p3, p4, p2) && IsMiddleY(p3, p4, p2)))
			return 1;
	return 0;
}

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
	int Find(size_t a) {
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


int main() {
	FASTIO;

	int N;
	cin >> N;

	DisJointSet lineSet(N);
	vector<Line> lines(N);
	//vector<bool> visit(N,false);

	for (auto& l : lines) {
		cin >> l.p1.x >> l.p1.y 
			>>l.p2.x >> l.p2.y ; 
	}

	for (int now = 0; now <N; now++) {
		
		for (int next = 0; next <N; next++) {
			if (lineSet.isSame(next, now))
				continue;

			if (CheckCCW(lines[now], lines[next])) {
				lineSet.Merge(now, next);
			}
		}
	}

	cout << lineSet.getSetCnt() << "\n"
		<< lineSet.getMaxSetSize() << "\n";

}
#endif 
                      
//Pos CheckCCW(Pos p1, Pos p2, Pos p3, Pos p4) {
//
//	Pos ret = {MAX_X+1,0};
//	double a = CCW(p1, p2, p3);
//	double b = CCW(p1, p2, p4);
//
//	double c = CCW(p3, p4, p1);
//	double d = CCW(p3, p4, p2);
//
//	if (a*b < 0 && c*d < 0)							//base
//		ret = GetCrossP(p1, p2, p3, p4);
//
//	if ((a*b==0 && (a||b)) || (c*d==0 && (c||d))) {	//one dot is on with other line
//		if (!a && IsMiddleP(p1, p2, p3))
//			ret = p3;
//		if (!b && IsMiddleP(p1, p2, p4))
//			ret = p4;
//		if (!c && IsMiddleP(p3, p4, p1))
//			ret = p1;
//		if (!d && IsMiddleP(p3, p4, p2))
//			ret = p2;
//	}
//
//	if (!a && !b && !c && !d) {						//one line
//		if (IsMiddleP(p3, p4, p1) || IsMiddleP(p1, p2, p3)) {
//			ret.y = 1;
//			if (p1 == p4)
//				ret = p4;
//			if (p3 == p2)
//				ret = p3;
//		}
//	}
//
//	return ret;
//}

//bool CheckCCW(Pos p1, Pos p2, Pos p3, Pos p4) {
//	double a = CCW(p1, p2, p3);
//	double b = CCW(p1, p2, p4);
//
//	double c = CCW(p3, p4, p1);
//	double d = CCW(p3, p4, p2);
//
//	if (a*b < 0  && c*d < 0)
//		return 1;
//
//	if (a == 0 || b == 0)
//		if ((a == 0 && IsMiddleX(p1, p2, p3) && IsMiddleY(p1, p2, p3)) ||
//			(b==0 && IsMiddleX(p1, p2, p4) && IsMiddleY(p1, p2, p4)))
//			return 1;
//
//	if (c == 0 || d == 0)
//		if ((c == 0 && IsMiddleX(p3, p4, p1) && IsMiddleY(p3, p4, p1)) ||
//			(d == 0 && IsMiddleX(p3, p4, p2) && IsMiddleY(p3, p4, p2)))
//			return 1;
//
//	return 0;
//}