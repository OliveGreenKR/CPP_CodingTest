#include "MyUtil.h"




/*----------------------
		str
----------------------*/
inline int MySTR::Ctoi(char ch) { return ch - '0'; }

string MySTR::Sum(string s1, string s2)
{
	::reverse(s1.begin(), s1.end());
	::reverse(s2.begin(), s2.end());

	while (s1.length() != s2.length())
		s1.append("0");

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
