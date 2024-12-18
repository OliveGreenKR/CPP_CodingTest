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

//sym, asym
pair<int, int> dfs(int n)
{
	if (n < 1)
		return { 0,0 };

	if (n == 1)
		return { 0,0 };
	if (n == 2)
		return { 1,0 };

	auto [sym1, asym1] = dfs(n - 1);
	auto [sym2, asym2] = dfs(n - 2);

	return { (1 + sym1 + sym2) , (sym1 * 2 + asym1 + (asym1 - sym2) * 2) };
}

int solution(int n) {

	auto res = dfs(n);
	return res.first + res.second + 1;
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
	cout << solution(3);
#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}