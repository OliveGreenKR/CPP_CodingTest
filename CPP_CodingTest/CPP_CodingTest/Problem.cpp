#include "pch.h"
#include <cstdio>
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)
#define M_Loop(i,st,M) for(int i=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int i=(st);i>(M);i--)
enum
{
    MAX_IN = 100'000+100
};

struct Heap
{
    int length=0;
    int heap[MAX_IN];
}Gheap;

int Pop(Heap& heap)
{
    int& len = heap.length;
    if (!len)
        return 0;
    int& anew = heap.heap[len];
    len--;

    int idx = 1;
    int& root = heap.heap[idx];
    int ret = root;

    root = anew;
    anew = 0;
    
    int child;
    heap.heap[2 * idx] > heap.heap[2 * idx + 1] ? child = 2 * idx : child = 2 * idx + 1;
    while (heap.heap[child] > heap.heap[idx])
    {
        ::swap(heap.heap[idx], heap.heap[child]);
        idx = child;
        heap.heap[2 * idx] > heap.heap[2 * idx + 1] ? child = 2 * idx : child = 2 * idx + 1;
    } 
    return ret;
}

void Push(int elm, Heap& heap)
{
    int& len = heap.length;
    int idx = ++len;

    heap.heap[idx] = elm;
    while (idx/2 && heap.heap[idx/2] < heap.heap[idx])
    {
        ::swap(heap.heap[idx], heap.heap[idx / 2]);
        idx /= 2;
    }
}

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
            cout << Pop(Gheap) << "\n";
            break;
        default:
            Push(x, Gheap);
            break;
        }
    }

	return 0;
}
#endif 
