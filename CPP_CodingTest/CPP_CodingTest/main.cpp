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

//hanoi Path
vector<vector<int>> getPath(const int n, int curr, int target, int empty)
{
	if (n == 1)
		return { {curr,target} };

	vector<vector<int>> result;

	vector<vector<int>> stage1 = getPath(n - 1, curr, empty, target);
	vector<vector<int>> stage2 = { {curr,target} };
	vector<vector<int>> stage3 = getPath(n - 1, empty, target, curr);
	result.insert(result.end(), stage1.begin(), stage1.end());
	result.insert(result.end(), stage2.begin(), stage2.end());
	result.insert(result.end(), stage3.begin(), stage3.end());

	return result;

}
vector<vector<int>> solution(int n) {
	return getPath(n, 1, 3, 2);
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