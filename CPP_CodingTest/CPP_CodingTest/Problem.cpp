#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <string>
#include <locale>
#include <deque>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

enum class F //function choice flag
{
	R = 'R',
	D = 'D'
};
enum Choice //state
{
	STACK = true,
	Q = false
};
bool state = Choice::Q;  //deque's state (Q or Stack)
deque<int> deq; 

inline void FuncR() //chage state
{
	state = state ^ true;
}

inline void FuncD()//pop
{
	switch (state)
	{
	case Choice::Q :
		deq.pop_front();
		break;
	case Choice::STACK :
		deq.pop_back();
		break;
	}
}
inline void ReadDeq() //read q and print [,,,,...]
{
	if (deq.empty())
	{
		cout << "[]\n";
		return;

	}
	auto ReadQ = [](deque<int>& deq) { int tmp = deq.front(); deq.pop_front(); return tmp;};
	auto ReadST = [](deque<int>& deq) { int tmp = deq.back(); deq.pop_back(); return tmp;};

	int (*Read)(deque<int>&) =  ReadQ;
	if (state == Choice::STACK)
		Read = ReadST;
	cout << "[";
	while (deq.size()>1)
		cout << Read(deq) << ",";
	cout << deq.front() << "]\n";
	deq.pop_back();
}

struct MyCIN : std::ctype<char>
{
	MyCIN() : std::ctype<char>(get_table()) {}
	static mask const* get_table()
	{
		static mask rc[table_size];
		rc[','] = std::ctype_base::space;
		rc['['] = std::ctype_base::space;
		rc[']'] = std::ctype_base::space;
		rc['\n'] = std::ctype_base::space;
		return &rc[0];
	}
};

int main()
{
	int T,N;

	cin >> T;
	cin.imbue(locale(cin.getloc(), new MyCIN));

	M_Loop(i, 0, T)
	{
		//init deq
		state = Choice::Q;
		string p;
		cin >> p;
		cin >> N;
		M_Loop(j, 0, N)
		{
			int n;
			cin >> n;
			deq.push_back(n);
		}
		for (char functioncall : p)
		{
			if (functioncall == static_cast<char>(F::R))
			{
				FuncR();
			}
			else
			{
				if (deq.size() == 0)
				{
					cout << "error\n";
					goto next;
				}
				FuncD();
			}
		}
		ReadDeq();
		next:;
	}
}
#endif 

