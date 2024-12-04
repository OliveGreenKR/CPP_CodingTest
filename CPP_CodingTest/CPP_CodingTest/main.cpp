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
using GuessMap = vector<unordered_set<int>>;

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
	const string infile = "./input.txt";
	const string outfile = "./output.txt";
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
	
	int q;
	fin >> q;

	for (int i = 0; i < q; ++i)
	{
		int n;
		

		fin >> n;
		vector<vector<int>> edges(n - 1, vector<int>(2));
		for (int j = 0; j < n-1; ++j)
		{
			fin >> edges[j][0] >> edges[j][1];
		}

		int g, k;
		fin >> g >> k;
		vector<vector<int>> guesses(g, vector<int>(2));
		for (int k = 0; k < g; ++k)
		{
			fin >> guesses[k][0] >> guesses[k][1];
		}
		

		cout << storyOfATree(n, edges, k, guesses) << "\n";
	}
   
	/*
	67/100
	21/100
	1/1
	0/1
	87/100
	*/

	/* [input2]
	19/50
	1/1
	217/250
	0/1
	67/1000
	*/

	/*
	* 34671/100000
	*/
#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}