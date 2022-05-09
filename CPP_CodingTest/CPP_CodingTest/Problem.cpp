#include "pch.h"
#pragma warning(disable: 4996)
#include <vector>
#include <queue>
#include <algorithm>

#ifdef BACK
#include <iostream>
#include <map>
#include <string>
#include <ctype.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)

enum
{
    Max = 100'000,
};
//map<int, string> dic_n;
map<string, int> dic_w;
string arr[Max+1];
int N, M;


int main()
{
    FASTIO;
    cin >> N >> M;
    M_Loop(i, 1, N+1)
    {
        string poke;
        cin >> poke;
        dic_w.emplace(poke,i);
        arr[i] = poke;
    }
    M_Loop(i, 0, M)
    {
        string input; cin >> input; 
        if (::isdigit(input[0]))
        {
           cout << arr[stoi(input)] << "\n";
        }
        else
        {
            cout << dic_w.at(input) << "\n";
        }
    }
    return 0;
}



#endif 
