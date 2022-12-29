#include "pch.h"
#pragma warning(disable: 4996)
#include <fstream>
#define NULL (0)
#ifdef BACK
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
using int64 = long long;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int> vertexes(8,-1);
vector<bool> visit(8,false);
vector<int> series(8,0);
int ans = 0;

bool IsConvex(double p1, double p2, double p3) {
    return p2/sqrt(2) >= (p1*p3/(p1+p3));
}

void CountForAns(int cnt) {

    if (cnt == 8) {
        for (int i = 0; i< 8; i++) {
            int p1 = i;
            int p2 = (p1+1)%8;
            int p3 = (p2+1)%8;
            if(!IsConvex(series[p1],series[p2],series[p3]))
                return;
        }
        ans++;
        return;
    }

    for (int i = 0; i<8; i++) {

		if (visit[i]!=false)
			continue;
		visit[i] = true;
        series[cnt] = vertexes[i];
        CountForAns(cnt+1);
        visit[i] = false;
    }
    
}

int main() {
	FASTIO;
    int N=8;

    for (int i = 0; i<N; i++) {
        cin >> vertexes[i];
    }
    CountForAns(0);
    cout << ans << "\n";
	return 0;
}
#endif 
                      
