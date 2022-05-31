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

	//시간 계산
	::sort(cars.begin(), cars.end());
	answer.resize(cars.size(),0);
	for (int j = 0; j < cars.size(); j++)
	{
		int now = cars[j];
		if (cartory.at(now).size()%2 != 0)
			cartory.at(now).push_back(maxT);
		for (int i = 0; i < cartory[now].size(); i += 2)
		{
			int inT = cartory[now][i];
			int outT = cartory[now][i+1];
			int payT = outT - inT;
			answer[j] += payT;
		}
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

	return answer;
}

int main()
{
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    solution(fees, records);
    return 0;
}