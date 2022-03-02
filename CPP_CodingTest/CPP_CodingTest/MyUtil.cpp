#include "MyUtil.h"




/*----------------------
		str
----------------------*/
inline int MySTR::Ctoi(char ch) { return ch - '0'; }

inline int MySTR::Stoi(const string& nstr)
{
	if (nstr.empty())
		return 0;

	int ret = 0;
	int tmp = 1;
	M_Loop_sub(i, nstr.length() - 1, -1)
	{
		int n = nstr[i] - '0';
		ret += n * tmp;
		tmp *= 10;
	}
	return ret;
}

string MySTR::Sum(string s1, string s2)
{
	::reverse(s1.begin(), s1.end());
	::reverse(s2.begin(), s2.end());
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 < len2)
	{
		while (s1.length() != s2.length())
			s1.append("0");
	}
	else
	{
		while (s1.length() != s2.length())
			s2.append("0");
	}

	string tmp;
	tmp.resize(s2.length() + 1, '0');

	M_Loop(i, 0, s2.length())
	{
		int sum = Ctoi(tmp[i]) + Ctoi(s1[i]) + Ctoi(s2[i]);
		tmp[i] = (sum % 10) + '0';
		tmp[i + 1] = (sum / 10) + '0';
	}

	if (tmp[tmp.length() - 1] == '0')
		tmp = tmp.substr(0, tmp.length() - 1);
	reverse(tmp.begin(), tmp.end());
	return tmp;
}
