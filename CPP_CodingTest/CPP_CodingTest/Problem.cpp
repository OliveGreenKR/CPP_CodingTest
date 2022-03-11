#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)
struct Node
{
	Node(int data) : _data(data)
	{}
	int _data = 0;
	Node* _right = nullptr;
	Node* _left = nullptr;
};
class MyDeque //_back 이 가장 최근에 들어온 원소이다.
{
public:
	MyDeque()
	{
		_back = nullptr;
		_front = nullptr;
	}
	~MyDeque()
	{
		if (!Empty())
		{
			if (_size == 1)
				delete _back;
			else
				delete _back, _front;
		}
	}

	void Push_back(int elm) //_back의 오른쪽에 추가
	{
		if (Empty() == true)
		{
			_front = new Node(elm);
			_back = _front;
			_back->_right = _front;
			_front->_left = _back;
		}
		else
		{
			Node* Other = new Node(elm);
			_back->_right = Other;
			Other->_left = _back;
			_back = Other;
		}
		_size++;
	}
	void Push_front(int elm) //_front의 왼쪽에 추가
	{
		if (Empty() == true)
		{
			_front = new Node(elm);
			_back = _front;
			_back->_right = _front;
			_front->_left = _back;
		}
		else
		{
			Node* Other = new Node(elm);
			_front->_left = Other;
			Other->_right = _front;
			_front = Other;
		}
		_size++;
	}
	int Pop_back()//_back pop
	{
		if (Empty() != true)
		{
			int top = _back->_data;
			Node* tmp = _back;
			_back = _back->_left;
			if (_back)
				_back->_right = nullptr;
			else
				_back = _front;//nullptr
			delete tmp;
			_size--;
			return top;
		}
		return -1;
	}
	int Pop_front()//_front pop
	{
		if (Empty() != true)
		{
			int top = _front->_data;
			Node* tmp = _front;
			_front = _front->_right;
			if (_front)
				_front->_left = nullptr;
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
		return _size == 0;
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
}GDeque;


void Ans(const string& cmd)
{
	if (cmd == "push_front")
	{
		int elm;
		cin >> elm;
		GDeque.Push_front(elm);
	}
	if (cmd == "push_back")
	{
		int elm;
		cin >> elm;
		GDeque.Push_back(elm);
	}

	else if (cmd == "pop_front")
		cout << GDeque.Pop_front() << "\n";
	else if (cmd == "pop_back")
		cout << GDeque.Pop_back() << "\n";
	else if (cmd == "size")
		cout << GDeque.Size() << "\n";
	else if (cmd == "empty")
		cout << static_cast<int>(GDeque.Empty()) << "\n";
	else if (cmd == "front")
		cout << GDeque.Front() << "\n";
	else if (cmd == "back")
		cout << GDeque.Back() << "\n";
}
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 0, N)
	{
		string cmd;
		cin.width(10);
		cin >> cmd;
		Ans(cmd);
	}
	return 0;
}



#endif 
