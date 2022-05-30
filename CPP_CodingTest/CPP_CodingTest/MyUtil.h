#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)

/*-----------------------
	String
-------------------------*/

namespace MySTR
{
	inline int Ctoi(char ch);
	inline int Stoi(const string& nstr);
	inline string Itos(int n);
	string Mul(string s1, string s2);
	string Sum(string s1, string s2);
	vector<string> Delim(string&& str, string& delim);
} 

/*----------------------
		Cin
-----------------------*/
struct MyCIN : std::ctype<char>
{
	MyCIN() : std::ctype<char>(get_table()) {}
	static mask const* get_table()
	{
		static mask rc[table_size];
		rc['.'] = std::ctype_base::space;
		rc['\n'] = std::ctype_base::space;
		return &rc[0];
	}
};
//cin.imbue(locale(cin.getloc(), new MyCIN));
