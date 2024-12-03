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

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Position structure with hash value
struct Pos
{
	int value;  // Hashed value of position

	// Constructor takes x, y coordinates and hashes them
	Pos(int x, int y) {
		value = x * 100000 + y;
	}

	// Equality operator for unordered_set/map usage
	bool operator==(const Pos& other) const {
		return value == other.value;
	}
};

// Hash function for Pos
struct PosHash
{
	size_t operator()(const Pos& pos) const {
		return hash<int>()(pos.value);
	}
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	// Store positions at each timestamp
	unordered_map<int, unordered_set<Pos, PosHash>> timeMap;
	// Store dangerous situations
	unordered_set<int> dangerSet;

	// Simulate robot movements
	for (const auto& route : routes)
	{
		int currTime = 0;

		// Process each point in the route except the last one
		for (int i = 0; i < route.size() - 1; i++)
		{
			// Get current and next positions
			int currX = points[route[i]][0];
			int currY = points[route[i]][1];
			int nextX = points[route[i + 1]][0];
			int nextY = points[route[i + 1]][1];

			// Move X coordinate first
			while (currX != nextX)
			{
				currX += (nextX > currX) ? 1 : -1;
				Pos pos(currX, currY);

				// If position already exists at this time, add to danger set
				if (!timeMap[currTime].insert(pos).second)
				{
					dangerSet.insert(currTime);
				}
				currTime++;
			}

			// Then move Y coordinate
			while (currY != nextY)
			{
				currY += (nextY > currY) ? 1 : -1;
				Pos pos(currX, currY);

				// If position already exists at this time, add to danger set
				if (!timeMap[currTime].insert(pos).second)
				{
					dangerSet.insert(currTime);
				}
				currTime++;
			}
		}
	}

	return dangerSet.size();
}

int main() {
	ifstream fin("./input.txt"); // 입력 파일 열기
	ofstream fout("./output.txt"); // 출력 파일 열기
#pragma region OpenFile
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