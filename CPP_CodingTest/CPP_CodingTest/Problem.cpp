#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int i=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int i=(st);i>(M);i--)

template <class _Ty = void>
struct Func
{

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{
		_Ty left, right;
		_Left < 0 ? left = -_Left : left = _Left;
		_Right < 0 ? right = -_Right : right = _Right;
		if (left < right)
			return false;
		else if (left > right)
			return true;
		else
			return _Left > _Right;
	}
};

priority_queue< int, vector<int>, Func<int>> Gq;

int main()
{
	FASTIO;
    int N;
    cin >> N;
    M_Loop(i, 0, N)
    {
        int x;
        cin >> x;
        switch (x)
        {
        case 0:
            if (Gq.empty())
            {
                cout << 0 << "\n";
                break;
            }
            cout << Gq.top() << "\n";
            Gq.pop();
            break;
        default:
            Gq.push(x);
        }
    }

	return 0;
}
#endif 
