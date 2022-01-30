#if 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


map<char, int> dial;
vector<char> flag;

int GetFlag(const char c)
{
	for (int i = 0; i < flag.size()-1; i++)
	{
		if (c < flag[i+1])
			return i;
	}
	return flag.size()-1;
}
int FindNUM(const char& c)
{
	int idx = GetFlag(c);

	char tmp = flag[idx];
	int ret = dial.at(tmp);
	return ret;
}

//숫자+2초 걸린다.
int main()
{
	flag = vector<char>{ 'A','D','G','J','M','P','T','W' };

	for (int i = 0; i < flag.size(); i++)
	{
		dial.emplace(make_pair(flag[i], i + 2));
	}

	string s;
	getline(cin, s);

	int sum = 0;
	
	for (char c : s)
	{
		sum += FindNUM(c) + 1;
	}

	cout << sum << endl;
}

#endif // 1
