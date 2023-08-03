#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
#include <iostream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using path = vector<int>; //{i,j,w}

const int INF = 10'000'001;

void choose_path(const path& path, vector<bool>& avail) {
    int i = path[0], j = path[1], cost = path[2];

}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
 
    //인접 리스트 형태로 정리 adj[i] = 'i 와 인접한 노드들의 vector'
    //paths => prioirty_queue 사용
    //선택된 집합 vs 선택된 집합과 인접한 정점
    static vector<bool> available(n+1, false);
    //static map<int,vector<int>> adj;
    static vector<vector<int>> adj(n+1);

    auto greater_path = [](const path& A, const path& B)->bool{ return A[2] > B[2]; };
    static priority_queue<path,vector<path>, decltype(greater_path)> pq(greater_path);


    /*
    1. pq 만들기
    2. 선택됨 정점과 인접한 정점 검색
    3.
    */
    for (path& p : paths) {
        pq.push(p);
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }

    path now;
    int cost;
    bool isGate = false , isSummit = false;

    while (!pq.empty()) {
        now = pq.top();
        pq.pop();

        cost = now[2];



    }

    /*
    now  = pq.pop();
    if( now == 현재 인접 정점이 아님)
        continue;
    
    chosen.push(now);
    cost =  now.cost;

    if ( now  in summits )
        summit = ::min(summit, now)
    if ( now in gates)
        gate = true

    if( gate == true && summit != INF )
        return {summit, cost}

    */
    return { 0,0 };
}
#endif 

#include <iostream>

int main() {
    vector<vector<int>> paths = { {3, 4, 4} ,{4, 5, 3},{4, 6, 1},{5, 6, 1} };
    vector<int> gates = { 1,3 };
    vector<int> summits = { 5 };

    solution(6, paths, gates, summits);
}