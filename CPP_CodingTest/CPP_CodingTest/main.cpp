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
int solution(string begin, string target, vector<string> words) {

	//add start
	words.push_back(begin);
	
	const int n = words.size();
	const int m = target.size();

	unordered_map<string, vector<int>> patternMap;
	//[pattern][word idx]

	bool bHasTarget = false;
	//build pattern map
	for (int i = 0; i < n; ++i)
	{
		if (words[i] == target)
			bHasTarget = true;

		for (int j = 0; j < m; ++j)
		{
			string p(words[i]);
			p[j] = '*';
			patternMap[p].push_back(i);
		}
	}

	if (bHasTarget == false)
		return false;

	vector<unordered_set<int>> adj(n); //[idx][adj set]
	//build adj list
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			string p(words[i]);
			p[j] = '*';

			const vector<int>& pv = patternMap[p];
			if(!pv.empty())
				adj[i].insert(pv.begin(), pv.end());
		}
		adj[i].erase(i);
	}

	//bfs
	queue<pair<int, int>> q; //[idx][cost]

	//start
	vector<bool> visit(n, false);
	q.push({ n-1 ,0 }); 

	while (!q.empty())
	{
		auto [idx, cost] = q.front();
		q.pop();

		if (words[idx] == target)
			return cost;

		for (const int& next : adj[idx])
		{
			if (visit[next])
				continue;
			visit[next] = true;
			q.push({ next,cost + 1 });
		}

	}

	return 0;
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
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}