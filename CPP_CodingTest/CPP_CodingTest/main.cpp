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

int findCorrect(int root, vector<bool>& visit, const vector<vector<int>>& adj, const GuessMap& guess)
{
	visit[root] = true;
	int correct = 0;

	for (int next : adj[root])
	{
		if (visit[next])
			continue;

		if (guess[root].count(next)) //guess true
		{
			correct++;
		}

		correct += findCorrect(next, visit, adj, guess);
	}

	return correct;
}

void recordCorrect(int root, int record, vector<bool>& visit, vector<int>& correct, const vector<vector<int>>& adj, const GuessMap& guess)
{
	correct[root] = record;
	visit[root] = true;

	for (int next : adj[root])
	{
		if (visit[next])
			continue;

		int delta = 0;
		if (guess[root].count(next))
			delta = -1;
		if (guess[next].count(root)) //inversion guess exists
			delta =  1;

		recordCorrect(next, record + delta, visit, correct, adj, guess);
	}
	return;
}



string storyOfATree(const int n, const vector<vector<int>>& edges, const int k, const vector<vector<int>>& guesses)
{

	//make adjlist
	vector<vector<int>> adj(n + 1);
	for (const auto& edge : edges)
	{
		const int u = edge[0];
		const int v = edge[1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//make guessMap
	GuessMap guessMap(n + 1);
	for (const auto& guess : guesses)
	{
		guessMap[guess[0]].insert(guess[1]);
	}


	vector<bool> visit(n + 1, false);//1-based index
	vector<int> correct(n + 1, 0);

	//find correctness in root == 1
	correct[1] = findCorrect(1, visit, adj, guessMap);

	fill(visit.begin(), visit.end(), false);
	recordCorrect(1, correct[1], visit, correct, adj, guessMap);

	//get p for wins
	int numerator = ::count_if(correct.begin(), correct.end(), [&k](const int x) {return x >= k; });
	int denominator = n;

	int gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	return to_string(numerator) + "/" + to_string(denominator);
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
#pragma region Close
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}