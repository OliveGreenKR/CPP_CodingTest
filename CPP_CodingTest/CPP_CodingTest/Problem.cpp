#include "pch.h"
#ifdef BACK
#include <iostream>
#include <vector>

using namespace std;

#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,n) for(int i=st;i<n;i++)
#define M_Loop_sub(i,st,n) for(int i=n;i>st;i--)

vector<int> Input;
vector<int> Operators(4, 0);

enum
{
	PLUS = 0,
	SUB = 1,
	MUL = 2,
	DIV = 3
};

int MIN = INT32_MAX;
int MAX = INT32_MIN;
int OperCNT = 0;

void Calcul(int cnt)
{
	if (cnt == OperCNT)
	{
		int result = Input[Input.size() - 1];
		if (result > MAX)
			MAX = result;
		if (MIN > result)
			MIN = result;
		/*cout << Input[Input.size() - 1] << "\n";*/
		return;
	}

	const int& left = Input[cnt];
	int& right = Input[cnt+1];
	int tmp = right;
	M_Loop(j, 0, Operators.size())
	{
		if (Operators[j] != 0)
		{
			Operators[j]--;
			switch (j)
			{
			case PLUS:
				right = left + right;
				Calcul(cnt + 1);
				break;
			case SUB:
				right = left - right;
				Calcul(cnt + 1);
				break;
			case MUL:
				right = left * right;
				Calcul(cnt + 1);
				break;
			case DIV:
				if (right == 0)
					return;
				right = left / right;
				Calcul(cnt + 1);
				break;
			}
			Operators[j]++;
			right = tmp;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	M_Loop(i, 0, N)
	{
		int k;
		cin >> k;
		Input.push_back(k);
	}
	M_Loop(i, 0, Operators.size())
	{
		cin >> Operators[i];
		OperCNT += Operators[i];
	}

	Calcul(0);

	cout << MAX << "\n" << MIN;

}

#endif 