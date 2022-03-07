#include "pch.h"
#ifdef BACK
#include <iostream>
#include <string>

using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,n,st) for(int i=(n);i>(st);i--)
using int64 = long long;
using float64 = long double;

enum
{
	VNULL = -1
};
struct Node
{
	Node(int data) : _data(data)
	{}
	int _data = 0;
	Node* _next =  nullptr;
	Node* _pre = nullptr;
};
class MyStack
{
public:
	MyStack()
	{
		_nodes = nullptr;
	}
	~MyStack() 
	{
		delete _nodes;
	}
	void Push(int elm)
	{
		if (Empty() == true)
		{
			_nodes = new Node(elm);
		}	
		else
		{
			Node* Other = new Node(elm);
			_nodes->_next = Other;
			Other->_pre = _nodes;
			_nodes = Other;
		}
		_size++;
	}
	int Pop()
	{
		if (Empty()!= true)
		{
			int top = _nodes->_data;
			Node* tmp = _nodes;
			_nodes = _nodes->_pre;
			if(_nodes)
				_nodes->_next = nullptr;
			delete tmp;
			_size--;
			return top;
		}
		return -1;
	}
	int Size()
	{
		return _size;
	}
	bool Empty()
	{
		if (_size == 0)
			return true;
		return false;
	}
	int Top()
	{
		if (Empty())
			return -1;
		return _nodes->_data;
	}

private:
	Node* _nodes;
	int _size=0;
}_Gstack;


void Ans(const string & cmd)
{
	if (cmd == "push")
	{
		int elm;
		cin >> elm;
		_Gstack.Push(elm);
	}

	else if (cmd == "pop")
		cout << _Gstack.Pop() << "\n";
	else if (cmd == "size")
		cout << _Gstack.Size() << "\n";
	else if (cmd == "empty")
		cout << static_cast<int>(_Gstack.Empty()) << "\n";
	else if (cmd == "top")
		cout << _Gstack.Top() << "\n";
}
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 0, N)
	{
		string cmd;
		cin.width(5);
		cin >> cmd;
		Ans(cmd);
	}

	return 0;
}
#endif 
