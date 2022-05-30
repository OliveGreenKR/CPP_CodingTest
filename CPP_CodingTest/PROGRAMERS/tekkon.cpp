#define tekk
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

//최대 공격력 return
//연승시 승수만큼, 패배시 k만큼 power up

// 최대 공격력 10^11
// 최대 상대방 수 200'000

using int64 = long long;

vector<int> dp(200'001,0);

inline bool IsWin(int64 me, int64 other)
{
	return me> other;
}

int getAns()
{
//한정된 회수 안에 최대 공격력을 가지도록 승ㅎ패 결정..
	return 0;
}

int solution2(vector<int64> player, int64 power, int64 k)
{
	int ans = 0;
	
	
	//이기면 연승+

	//지면 k+

	//큰거 선택..

	return ans;
}

#ifdef tekk1
int main()
{
	vector<vector<int64>> players
	{
		{10,11,15,14,16,18,19,20},
		{1,2,4,7},
		{1,2,1,2,1}
	};
	vector<int64> ks = { 2,2,100};
	vector<int64> power = { 10,1,2};

	for (int i = 0; i<players.size(); i++)
		cout << solution2(players[i], power[i], ks[i]) << "\n";

	return 0;
}
#endif // card