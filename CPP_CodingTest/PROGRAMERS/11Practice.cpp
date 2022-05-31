#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cmath>
using namespace std;
inline int getTime(string& time)
{
    return stoi(time.substr(0, 2))*60 + stoi(time.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	unordered_map<int, vector<int>> cartory;
	vector<int> cars; //caridx record

	const int baseT = fees[0];
	const int baseC = fees[1];
	const int unitT = fees[2];
	const int unitC = fees[3];

	const int maxT = 23*60+59;

	for (string str : records)
	{
		//records 분리
		stringstream in(str);
		string time, car;
		in >> time >> car;
		const int cidx = stoi(car);

		//시간 기록
		if (cartory.find(cidx) == cartory.end())
		{
			cartory.insert({ cidx,{ getTime(time)} });
			cars.push_back(cidx);
		}
		else
		{
			cartory.at(cidx).push_back(getTime(time));
		}
	}

	::sort(cars.begin(), cars.end());
	answer.resize(cars.size(),0);
	for (int j = 0; j < cars.size(); j++)
	{
		int now = cars[j];
		if (cartory.at(now).size()%2 != 0)
			cartory.at(now).push_back(maxT);
		//시간계산
		for (int i = 0; i < cartory[now].size(); i += 2)
		{
			int inT = cartory[now][i];
			int outT = cartory[now][i+1];
			int payT = outT - inT;
			answer[j] += payT;
		}

		//비용계산
		int& ans = answer[j];
		if (ans> baseT)
		{
			ans = static_cast<int>(::ceil((ans-baseT)/static_cast<double>(unitT)))*unitC + baseC;
		}
		else
		{
			ans = baseC;
		}
	}
	return answer;//
}
