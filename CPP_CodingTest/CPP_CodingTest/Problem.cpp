#if 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int>> cases;

void PrintResult(const int& T)
{
	for (int i = 0; i < T; i++)
	{
		int H = cases.at(i)[0];
		int W = cases.at(i)[1];
		int N = cases.at(i)[2]-1;

		cout << N % H +1;
		cout.width(2);
		cout.fill('0');
		cout << N / H + 1 << endl;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		vector<int> tp(3);
		for (int j = 0; j < 3; j++)
		{
			int tmp;
			cin >> tmp;
			tp[j] =  tmp;
		}
		cases.insert(make_pair(i, tp));
	}

	PrintResult(T);


	return 0;
}

#endif // 1
