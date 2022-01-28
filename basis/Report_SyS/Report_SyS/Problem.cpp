#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	vector<string> verb;

	getline(cin, s);

	s = ' ' + s + ' ';

	int start = 0, end = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			end = i;
			string tmp = s.substr(start, end - start);
			if(start < s.size())
			start = i+1;

			if(tmp.length()!=0)
				verb.push_back(tmp);
		}
	}

	cout << verb.size();

	return 0;
}
