#include "pch.h"
#ifdef BACK

#include <vector>
#include <list>
#include <algorithm>
#include<string>

#include <cmath>
#include <iostream>
using namespace std;


int GetAns(int here, int dest)
{
	int dist = dest - here;
	int N = 1;

	while( true)
	{
		int _min = pow(N,2);

		if ( dist > _min)
		{
			N++;
		}

		else
		{
			N--; 

			if( dist > N*(N+1))
				return 2*N+1;
			else
			{
				return 2*N;
			}
		}
	}
}


int main()
{
	int x, y;
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		cout << GetAns(x, y) << endl;
	}

	return 0;
}
#endif