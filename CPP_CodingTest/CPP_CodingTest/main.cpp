#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <unordered_map>
#include <unordered_set>
#include <numeric> //gcd
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // 파일 입출력을 위한 헤더 추가
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>


#define OUT

using namespace std;

const int INF = 1e5;
const int NONE = 1e4;


int recordSunSUM(int now, int parent, const vector<int>& num, const vector<vector<int>>& adj, vector<int>& record)
{
    const int n = num.size();

    if (now < 0 || now >= n)
        return 0;

    int result = num[now];

    for (const int next : adj[now])
    {
        if (next == parent)
            continue;
        result += recordSunSUM(next, now, num, adj, record);
    }

    //record
    record[now] = result;
    return result;
}


//최대 크기가 m이하인 그룹의 최소 개수
int findMinGroups(int m, int root, int parent,  const vector<int>& accum, const  vector<vector<int>>& adj)
{
    if (root == NONE)
        return 0;

    int gcount = 1; //기본 그룹 수 

    //m이하의 서브트리
    if (accum[root] <= m)
        return gcount;

    //find next child..
    vector<int> childs;
    for (const int next : adj[root])
    {
        if (next != parent)
            childs.push_back(next);
    }
    int left = childs[0];
    int right = childs[1];
    /* Case 1 : 둘 다 분리해도 불가 -> 'm이 너무 작다'  ->
       이진탐색 시 'k보다 많은 그룹'이 나와야 m을 증가시킴*/
    if (accum[root] - accum[left] - accum[right] > m)
        return INF;

    /*Case 2 : 자식 하나 분리 */
    //둘 중 가능한 것이 있다면 최대한 작은 나머지를 독립시켜야함
    if (accum[root] - accum[left] <= m || accum[root] - accum[right] <= m)
    {

        if (accum[right] > accum[left])
        {
            //left is smaller
            gcount += findMinGroups(m, left, root, accum, adj);
        }
        else
        {
            gcount += findMinGroups(m, right, root, accum, adj);
        }
    }
    else
    {
        /*Case 3 : 둘 다 분리해야 가능*/
        gcount += findMinGroups(m, left,root, accum, adj)
            + findMinGroups(m, right,root, accum, adj);
    }


    //최대 INF를 넘지 않도록 결과 리턴.
    return min(INF, gcount);
}


//그룹 개수 k일때 가장 큰 집합의 최소 크기 반환
int binarySearch(int k, const vector<int>& record, const vector<vector<int>>& adj)
{
    //root = 0
    //집합의 크기 범위 [1..all]
    int left = 1;
    int right = record[0]; //root = 0
    int mid = 0;
    int gcount = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        //가장 큰 집합의 크기가 mid 이하일때의 그룹 개수
        gcount = findMinGroups(mid, 0, -1, record, adj);

        //k 초과의 그룹 생성 가능 -> 집합 크기 증가
        if (gcount > k)
            left = mid + 1;

        //k 이하의 그룹 생성 가능 -> 집합 크기 감소
        if (gcount <= k)
            right = mid; //mid값을 포함해야 함
    }

    return mid;
}


int solution(int k, vector<int> num, vector<vector<int>> links) {

    const int n = num.size();

    vector<vector<int>> adj(n);
    //build bidirectional adj[i]
    for (int i = 0; i < n ; ++i)
    {
        const auto link = links[i];

        adj[i].push_back(link[0]);
        adj[i].push_back(link[1]);

        adj[link[0]].push_back(i);
        adj[link[1]].push_back(i);
    }

    vector<int> record(NONE+1); //record accumulation
    recordSunSUM(0, -1,num, adj, record);

    return binarySearch(k, record, links);
}

int main() {
    string infile = "./input.txt";
    string outfile = "./output.txt";
#pragma region OpenFile
    ifstream fin(infile);
    ofstream fout(outfile);
    if (!fin)
    {
        cerr << "Unable to open input file";
        return 1; // 입력 파일을 열 수 없으면 프로그램 종료
    }
    if (!fout)
    {
        cerr << "Unable to open output file";
        return 1; // 출력 파일을 열 수 없으면 프로그램 종료
    }
#pragma endregion
    vector<int> num = { 12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1 };
    vector<vector<int>> links = { {-1, -1}, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 8, 5 }, { 2, 10 }, { 3, 0 }, { 6, 1 }, { 11, -1 }, { 7, 4 }, { -1, -1 }, { -1, -1 } };
    int k = 3;
    cout << solution(3, num,links);

#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}