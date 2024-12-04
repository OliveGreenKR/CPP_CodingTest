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
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>

#define OUT

using namespace std;

int prims(int n, vector<vector<int>> edges, int start) {
    //edges [from][to][weight]

    //build edge map
    unordered_map<int, vector<pair<int, int>>> edgeMap;
    for (const auto& edge : edges)
    {
        edgeMap[edge[0]].push_back({ edge[2],edge[1] }); //weight, to
        edgeMap[edge[1]].push_back({ edge[2],edge[0] });
    }

    //prim - MST
    vector<int> visit(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //[cost][to]

    pq.push({ 0,start });
    int weightSum = 0;

    while (!pq.empty())
    {
        const auto [weight, to] = pq.top();
        pq.pop();

        if (visit[to])
            continue;

        visit[to] = true;
        weightSum += weight;

        for (const auto& e : edgeMap[to])
        {
            if (!visit[e.second])
            {
                pq.push(e);
            }
        }
    }

    return weightSum;

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
		return 1; // �Է� ������ �� �� ������ ���α׷� ����
	}
	if (!fout)
	{
		cerr << "Unable to open output file";
		return 1; // ��� ������ �� �� ������ ���α׷� ����
	}
#pragma endregion
	

#pragma region CloseFile 
	fin.close(); // �Է� ���� �ݱ�
	fout.close(); // ��� ���� �ݱ�
#pragma endregion
	return 0;
}