#define tekk
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

//�ִ� ���ݷ� return
//���½� �¼���ŭ, �й�� k��ŭ power up

// �ִ� ���ݷ� 10^11
// �ִ� ���� �� 200'000

using int64 = long long;

vector<int> dp(200'001,0);

inline bool IsWin(int64 me, int64 other)
{
	return me> other;
}

int getAns()
{
//������ ȸ�� �ȿ� �ִ� ���ݷ��� �������� �¤��� ����..
	return 0;
}

int solution2(vector<int64> player, int64 power, int64 k)
{
	int ans = 0;
	
	
	//�̱�� ����+

	//���� k+

	//ū�� ����..

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