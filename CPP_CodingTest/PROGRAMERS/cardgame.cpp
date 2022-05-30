#define card1

#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

//같은 카드가 10장중에 2장이상
//서로다른 플레이어가 같은 카드를 가지고 있을 때
//잘못된 라운드를 기록하시오
enum
{
	MAXC = 52+1,
	MAXR = 100
};

int solve( vector<vector<int>> cards1, vector<vector<int>> cards2)
{
	vector<vector<int>> log1(2,vector<int>(53, 0));
	vector<vector<int>> log2(2,vector<int>(53, 0));
	
	int answer = 0;
	for (int i = 0; i < cards1.size();i++)//round
	{
		log1[0] = vector<int>(53, 0);
		log2[0] = vector<int>(53, 0);
		::swap(log1[0], log1[1]);
		::swap(log2[0], log2[1]);
		int p1=0, p2=0;
		int Max = 0;
		for (int j = 0; j<5; j++)
		{
			int c1 = cards1[i][j];
			int c2 = cards2[i][j];
			log1[1][c1]++;
			log2[1][c2]++;
		}

		int cnt1=0, cnt2 =0;
		for (int j = 1; j<53; j++)
		{
			if ((log1[1][j]&&log2[1][j]) || (log1[1][j]>1 || log2[1][j]>1) )
			{
				answer++;
				break;
			}
			else if (log1[1][j]&&log1[0][j]) 
				cnt1++;
			else if (log2[1][j]&&log2[0][j])
				cnt2++;
			if (cnt1>1|| cnt2>1)
			{
				answer++;
				break;
			}
		}
	}
	return answer;
}

#ifdef card
int main()
{
	vector<vector<vector<int>>>cards1 =
	{
		{
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10} 
		},
		{
			{13, 21, 24, 29, 50},
			{1, 12, 20, 21, 32},
			{16, 26, 34, 46, 52},
			{9, 11, 16, 16, 21},
			{3, 8, 10, 16, 20}
		}
	};
	vector<vector<vector<int>>> cards2 =
	{
		{
			{5, 7, 9, 11, 13},
			{ 11, 13, 15, 17, 19 }
		} ,
		{
			{5, 10, 15, 41, 49},
			{6, 14, 15, 19, 46},
			{5, 42, 43, 51, 52},
			{5, 6, 11, 13, 45},
			{5, 9, 11, 13, 45}
		}
	};

	for (int i = 0; i< cards1.size(); i++)
	{
		cout << solve(cards1[i], cards2[i]) << "\n";
	}

}
#endif // card
