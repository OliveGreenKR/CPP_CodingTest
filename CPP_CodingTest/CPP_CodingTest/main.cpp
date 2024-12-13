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

//find all possible values in dfs.
int dfs(long long current, int remainingPlus)
{
	
	if (current < 3 || current < pow(3, remainingPlus / 2))
		return 0;

	if (current == 3 && remainingPlus == 2)
		return 1;

	int result = 0;

	if (current % 3 == 0 && remainingPlus >= 2)
		result += dfs(current/3, remainingPlus-2);


	result += dfs(current - 1, remainingPlus + 1);

	return result;
}

int solution(int n) {

	return dfs(n, 0);
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