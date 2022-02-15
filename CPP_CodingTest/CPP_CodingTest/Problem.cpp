#include "pch.h"
#ifdef BACK

#include <cstdio>
#include<vector>
using namespace std;

int main()
{
	struct Size {
		int _weight;
		int _height;

		bool operator>(const Size& other) 
		{ return (_weight > other._weight && _height > other._height); }
	};
	vector<Size> datas;
	
	int N;
	scanf_s("%d", &N);

	vector<int> ranks(N,1);

	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf_s("%d%d", &x, &y);
		datas.push_back( Size{x,y} );
	}

	for (Size now : datas)
	{
		for (int i = 0; i < N; i++)
		{
			Size other = datas[i];
			if (now > other)
				ranks[i]++;
		}
	}
	
	for (int rank : ranks)
	{
		printf("%d ", rank);
	}
	
}

#endif