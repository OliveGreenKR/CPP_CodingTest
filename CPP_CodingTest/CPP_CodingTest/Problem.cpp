#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
using Vec64 = vector<int64>;

enum : int64
{
	MAX_IN = 100'000,
	MAX_SIZE = 1 << 18,
	MAX_H = 1'000'000'000
};

Vec64 Arr(MAX_IN,0);
Vec64 Tree(MAX_SIZE,0);

//segment tree
int64 init(Vec64& arr, Vec64& tree, int node, int start, int end)
{
	
	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;
	return tree[node] = ::min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end),
		[&arr](int64 A, int64 B)
		{
			return arr[A] < arr[B];
		}); //구간 내 최소값 인덱스를 저장
}

//구간에서 최소 막대 높이 구하기
int64 query(Vec64& array, Vec64& tree, int node, int start, int end, int left, int right)
{
	// 찾아야하는 구간과 노드구간이 겹치지 않을 때
	if (end<left || start>right)
		return -1;
	// 찾아야하는 구간내에 노드구간이 포함될 때
	else if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int64 leftQuery = query(array, tree, node * 2, start, mid, left, right);
	int64 rightQuery = query(array, tree, node * 2 + 1, mid + 1, end, left, right);

	// 찾는 구간이 노드구간에 포함되거나, 부분적으로 겹치는 경우
	if (leftQuery == -1)
		return rightQuery;

	else if (rightQuery == -1)
		return leftQuery;

	else return ::min(leftQuery, rightQuery,[&array](int64 A, int64 B)
		{
			return array[A] < array[B];
		});
}

int64 getMaxArea(vector<int64>& array, vector<int64>& tree, int start, int end,int size)
{
	int idx = query(array, tree, 1, 0, size-1, start, end);
	int64 area = (end - start+1) * array[idx];

	//왼쪽 막대 존재하면 왼쪽 최대 넓이 구하기
	if (start < idx)
	{
		int64 temp = getMaxArea(array, tree, start, idx - 1,size);
		area = ::max(area, temp);
	}

	//오른쪽 막대 존재하면 오른쪽 최대 넓이 구하기
	if (idx < end)
	{
		int64 temp = getMaxArea(array, tree, idx + 1, end,size);
		area = ::max(area, temp);
	}

	return area;
}

int main()
{
	
	FASTIO;

	while (true)
	{
		int T;
		cin >> T;
		if (T < 1)
			break;

		M_Loop(i, 0, T)
			cin >> Arr[i];

		init(Arr, Tree, 1, 0, T-1);
		cout << getMaxArea(Arr, Tree, 0, T-1,T) << "\n";
	}

	return 0;
}

#endif 
