#if 1
#include <vector>

#include <list>
#include <algorithm>
#include<string>
#include <iostream>
using namespace std;

void AddList(const string& str, list<int>& ans)
{
	for (char c : str)
	{
		ans.push_front(c - '0');
	}
}


int main()
{
	string A, B;
	cin >> A >> B;
	
	list<int> ans;

	AddList(A, ans);
	AddList(B, ans);
	
	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		cout << *it;
	}
	return 0;
}
#endif