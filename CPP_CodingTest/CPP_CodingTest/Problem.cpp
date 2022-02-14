#include "pch.h"
#ifdef BACK

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


//field = ������ �� �ִ� ���ҵ�
//combis = ������ ����
//now = ������ ���� index
//cnt = ������ ����
static vector<vector<int>> GCombies;

void Combination(vector<pair<int,bool>>& field, vector<int>& combis,int now=0, int cnt=0)
{
	if (cnt == combis.size())
	{
		vector<int> tmp = combis;
		GCombies.push_back(tmp);
		return;
	}

	else
	{
		for (int i = now; i < field.size(); i++)
		{
			if (field[i].second == true)
			{
				continue;
			}
			else
			{
				field[i].second == true;
				combis[cnt] = field[i].first;
				Combination(field, combis, i + 1, cnt + 1);
				field[i].second = false;
			}
		}
	}
	
}
int main() {
	int N, M;
	scanf_s("%d%d", &N, &M);

	//vector<int> cards;
	vector<pair<int, bool>> checkfield;
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf_s("%d", &n);
		//cards.push_back(n);
		checkfield.push_back(make_pair(n, false));
	}
	vector<int> combi(3);
	priority_queue<int> sums;

	Combination(checkfield, combi);

	for (vector<int> com : GCombies)
	{
		int sum = 0;
		for (int i : com)
		{
			sum += i;
		}
		if(sum <= M)
			sums.push(sum);
	}

	printf("%d\n", sums.top());
}

#endif