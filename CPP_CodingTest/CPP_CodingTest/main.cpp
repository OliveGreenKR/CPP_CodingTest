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

struct State
{
	State() {};
	State(const State& other) : move(other.move), x(other.x), y(other.y) {};

	int move = 0;
	int x;
	int y;

	bool operator >(const State& B)
	{
		return this->move > B.move;
	}
};

int solution(vector<string> board) {

	const vector<int> dirX = { 1,0,0,-1 };
	const vector<int> dirY = { 0,1,-1,0 };

	const int row = board.size();
	const int col = board[0].size();

	auto isBlocked = [&board, &row, &col](const int x, const int y)
		{
			return (x >= row || x < 0 || y >= col || y < 0 || board[x][y] == 'D');
		};

	//find start and dest
	State start;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (board[i][j] == 'R')
			{
				start.x = i;
				start.y = j;
			}
		}
	}

	priority_queue<State, vector<State>, greater<>> pq;
	State now;

	now.x = start.x;
	now.y = start.y;
	now.move = 0;
	board[now.x][now.y] = '*';
	pq.push(now);

	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();
		

		//find next
		for (int i = 0; i < 4; ++i)
		{
			State next(now);
			while (!isBlocked(next.x, next.y))
			{
				next.x += dirX[i];
				next.y += dirY[i];
			}
			next.x -= dirX[i];
			next.y -= dirY[i];
			++next.move;

			if (board[next.x][next.y] == 'G')
				return next.move;

			if (board[next.x][next.y] != '*')
			{
				board[next.x][next.y] = '*';
				pq.push(next);
			}
		 
		}
		
	}

	//impossible
	return -1;
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
	cout << solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });

#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}