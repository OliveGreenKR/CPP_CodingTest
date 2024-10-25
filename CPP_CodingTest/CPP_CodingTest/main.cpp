#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <deque>
#include <cmath>
#include <limits>

#define OUT

using namespace std;


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    //주어진 cities 로
    //Union-Find 로 묶음

    //만들어진 총 집합의 개수 : S 

    //각 집합에서
        //최소 도서관 건설 개수 => 1개
        //최도 도로 건설 개수 => (i집합 원소개수 -1) = ki

    //건설할 도로 개수 road
    //건설할 도시 개수 city.

    //road  -> [sum(ki)]
    //lib -> [S]

    //road <=> lib 랑  1:1 교환 가능. 
    //즉, road + lib 은 항상 같은 값을 유지해야함
        //근데 lib은 항상 최소 개수를 유지해야하니 1:1이 교환이 이득이라면, 전부 도서관을 도시마다 세우는 것이됨.
        //처음부터 예외처리 가능 ( c_road >= clib )-> return c_lib*n;
    
    
    //해당 조건에서 (c_lib * lib + c_road * road) 의 최소 비용을 찾는 함수
}

int main() {

}