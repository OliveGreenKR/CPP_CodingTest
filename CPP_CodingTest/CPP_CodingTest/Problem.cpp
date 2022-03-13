#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
deque<int> dq;
int cnt = 0;

inline void Func1() { dq.pop_front();}
inline void Func2(int n) {
    for (int i = 0; i < n; i++)
    {
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
        cnt++;
    } 
}
inline void Func3(int n) {
    for (int i = 0; i < n; i++)
    {
        int tmp = dq.back();
        dq.pop_back();
        dq.push_front(tmp);
        cnt++;
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) //ÃÊ±âÈ­
        dq.push_back(i);

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        int index=0;
        if (dq.front() == num)
        {
            Func1();
            continue;
        }
        while (dq[index] != num)
            index++;
        (index) <= (dq.size() - index) ? Func2(index) : Func3(dq.size() - index);
        Func1();
    }
    cout << cnt;
}
#endif 

