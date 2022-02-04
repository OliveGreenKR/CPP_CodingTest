#if 1

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int cache[15][15];

int GetAns(const int& k, const int& n)
{
	if (k < 0 || n < 0)
		return 0;
	int& ret = cache[k][n - 1];

	if (ret != 0)
		return ret;

	if (k == 0)
		return ret = n;

	return ret = GetAns(k - 1, n) + GetAns(k, n - 1);
}

int main()
{
	
	vector<int> ans;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;

		ans.push_back(GetAns(k, n));
	}

	for(int a :  ans)
	{
		cout << a << endl;
	}
}

#endif // 1
