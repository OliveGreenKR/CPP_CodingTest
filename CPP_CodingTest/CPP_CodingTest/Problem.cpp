#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

enum
{
	
};

struct Node
{
	Node(int Idx) : idx(Idx) {};
	int idx;
	vector<Node*> adj;
};


int main()
{
	FASTIO;
	
	return 0;
}

#endif 




