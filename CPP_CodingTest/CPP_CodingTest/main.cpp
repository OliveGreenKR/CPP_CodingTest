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

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	const long long INF = 2e9;
	//모든 노드 쌍의 최단 거리를 구함 
	   //dist[i][j] = i에서 j 까지의 최단 비용
	vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}

	//bidirectional fares
	for (const auto& edge : fares)
	{
		dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	long long result = dist[s][a] + dist[s][b]; //move each other
	for (int k = 1; k <= n; ++k)
	{
		result = min(result, dist[s][k] + dist[k][a] + dist[k][b]);
	}

	return result;
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