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

unordered_map<int, vector<int>> children;

//{not_attend, attend}
pair<int, int> dfs(int now , const vector<int>& sales) {

	//leaf
	if (children.find(now) == children.end()) 
		return { 0, sales[now - 1] }; 

	int sum = 0, min_diff = INT32_MAX;
	bool flag = false;

	for (auto next : children[now])
	{
		const auto [not_attend, attend] = dfs(next, sales);

		//case 1 : attend now
			//sum of child [attend or not]
		sum += min(not_attend, attend);

		//case 2 : other team attend
		if (not_attend >= attend) 
			flag = true;

		//case 3 :  no one attend
			//forcely make child attend
		min_diff = min(min_diff, attend - not_attend);
	}

	if (flag) 
		return { sum, sales[now - 1] + sum };
	return { sum + min_diff, sales[now - 1] + sum };
   
}

int solution(vector<int> sales, vector<vector<int>> links) {

	for (auto link : links)
	{
		children[link[0]].push_back(link[1]);
	}

	const auto [not_attend, attend] = dfs(1, sales);

	return min(not_attend, attend);
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

#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}