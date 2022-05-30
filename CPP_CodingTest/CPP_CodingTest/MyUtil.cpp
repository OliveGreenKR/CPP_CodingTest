#include "MyUtil.h"

enum
{
	MAX_LEN = 1200
};

/*----------------------
		str
----------------------*/
inline int MySTR::Ctoi(char ch) { return ch - '0'; }

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

inline string MySTR::Itos(int n)
{
	string ret;
	int i = 0;
	while (n)
	{
		ret[i] = n % 10;
		n /= 10;
	}
	::reverse(ret.begin(), ret.end());
	return ret;
}

string MySTR::Mul(string s1, string s2)
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
	tmp.resize(MAX_LEN, '0');

	M_Loop(i, 0, s2.length())
	{
		int mul = Ctoi(tmp[i]) + (Ctoi(s1[i]) * Ctoi(s2[i]));
		tmp[i] = (mul % 10) + '0';
		tmp[i + 1] = (mul / 10) + '0';
	}
	int idx = 0;
	while (tmp[idx] != '0')
		idx++;

	tmp = tmp.substr(0, idx);
	reverse(tmp.begin(), tmp.end());
	return tmp;
}

vector<string> MySTR::Delim(string&& str, string& delim)
{
	vector<string> ret;//[reporter][reportee]
	size_t pos = 0;
	while ((pos = str.find(delim)) != string::npos)
	{
		ret.push_back(str.substr(0, pos));
		str.erase(0, pos + delim.length());
	}
	ret.push_back(str);
	return ret;
}

//vector<string> Delim(string& str)
//{
//	stringstream in(str);
//	string a, b;
//	in >> a >> b;
//}