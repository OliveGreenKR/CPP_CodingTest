#pragma once
#include <iostream>
#include <algorithm>
#include <string>
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
} 

