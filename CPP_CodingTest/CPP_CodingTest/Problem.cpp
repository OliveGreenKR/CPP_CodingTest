#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=(st);i<(n);i++)
#define M_Loop_sub(i,st,n) for(int i=(st);i>(n);i--)

int Arr[20010];
int front = 10000;
int back = 10000;

string cmd;
int main()
{
	FASTIO;
	int N;
	cin >> N;

	M_Loop(i, 0, N)
	{
		cin.width(10);
		cin >> cmd;
		char ck = cmd[1];
		
		if (ck == 'u')
		{
			char ck2 = cmd[5];
			if (ck2 == 'f') cin >> Arr[--front];
			if (ck2 == 'b')	cin >> Arr[back++];
		}
		else if (ck == 'o')
		{
			char ck2 = cmd[5];
			if (ck2 == 'r') { back - front ? cout << Arr[front++] : cout << -1; cout << "\n"; }
			if (ck2 == 'a') { back - front ? cout << Arr[--back] : cout << -1; cout << "\n"; }
		}
		else if (ck == 'i')
			cout << back - front << "\n";
		else if (ck == 'm')
			cout << !static_cast<bool>(back - front) << "\n";
		else if (ck == 'r')
		{back - front ? cout << Arr[front] : cout << -1; cout << "\n";}
		else if (ck == 'a')
		{back - front ? cout << Arr[back-1] : cout << -1; cout << "\n";}
	}
	return 0;
}



#endif 
