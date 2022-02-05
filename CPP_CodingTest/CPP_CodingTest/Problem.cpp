#if 1
#include <vector>
#include <algorithm>
#include<string>
#include <iostream>
using namespace std;

void AddArr(const string& str, vector<int>& arr)
{
	int i = 0;
	for (char c : str)
	{
		int& sum = arr[9999 - i];
		if (sum == -1)
			sum = 0;
		sum += (c - '0');
		i++;
	}
}

void CleanArr(vector<int>& arr)
{

	for (int i = 0; i < arr.size(); i++)
	{
		int& v = arr[9999 - i];
		if (v == -1)
			break;

		if (v > 9)
		{
			int& next = arr[9999 - i - 1];
			if (next == -1)
				next = 0;
			int tmp = v;
			v = tmp % 10;
			next += tmp / 10;
		}
	}

}

int main()
{
	string A, B;
	cin >> A >> B;
	::reverse(A.begin(), A.end());
	::reverse(B.begin(), B.end());

	vector<int> ans(100001, -1);

	AddArr(A, ans);
	AddArr(B, ans);
	CleanArr(ans);

	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		if (*it != -1)
			cout << *it;
	}
	return 0;
}
#endif