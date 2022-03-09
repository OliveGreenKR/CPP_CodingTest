#include "pch.h"
#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
using int64 = long long;
using float64 = long double;

struct Node
{
	Node(int data) : _data(data)
	{}
	int _data = 0;
	Node* _next = nullptr;
	Node* _pre = nullptr;
};
class MyQueue 
{
public:
	MyQueue()
	{
		_back = nullptr;
		_front = nullptr;
	}
	~MyQueue()
	{
		delete _back, _front;
	}

	void Push(int elm)
	{
		if (Empty() == true)
		{
			_front = new Node(elm);
			_back = _front;
			_back->_next = _front;
			_front->_pre = _back;
		}
		else
		{
			Node* Other = new Node(elm);
			_back->_next = Other;
			Other->_pre = _back;
			_back = Other;
		}
		_size++;
	}
	int Pop()//back이 제일 최신
	{
		if (Empty() != true)
		{
			int top = _front->_data;
			Node* tmp = _front;
			_front = _front->_next;
			if (_front)
				_front->_pre = nullptr;
			else
				_back = _front;//nullptr
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
	int Front()
	{
		if (Empty())
			return -1;
		return _front->_data;
	}
	int Back()
	{
		if (Empty())
			return -1;
		return _back->_data;
	}

private:
	Node* _back;
	Node* _front;
	int _size = 0;
}_GQueue;


void Ans(const string & cmd)
{
	if (cmd == "push")
	{
		int elm;
		cin >> elm;
		_GQueue.Push(elm);
	}

	else if (cmd == "pop")
		cout << _GQueue.Pop() << "\n";
	else if (cmd == "size")
		cout << _GQueue.Size() << "\n";
	else if (cmd == "empty")
		cout << static_cast<int>(_GQueue.Empty()) << "\n";
	else if (cmd == "front")
		cout << _GQueue.Front() << "\n";
	else if (cmd == "back")
		cout << _GQueue.Back() << "\n";
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
