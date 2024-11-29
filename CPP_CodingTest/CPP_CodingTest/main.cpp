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

int checkGuessInRoot(int root, vector<bool>& visit,const vector<vector<int>>& adj, const GuessMap& guesses)
{
	visit[root] = true;
	int correct = 0;

	for (auto next : adj[root])
	{
		if (visit[next]) //visited already
			continue;

		if (guesses[root].count(next)) //guess correct
		{
			correct++;
		}

		correct += checkGuessInRoot(next, visit, adj, guesses);
	}

	return correct;
}

void recordDeltaCorrection(int root, int delta, vector<bool>& visit, vector<int>& deltaCorrections, const vector<vector<int>>& adj, const GuessMap& guesses)
{
	deltaCorrections[root] = delta;
	visit[root] = true;

	for (auto next : adj[root])
	{
		if (visit[next]) //visited already
			continue;

		int newdelta = delta;
		if (guesses[root].count(next)) //guess 
		{
			newdelta--;
		}
		if (guesses[next].count(root)) //guess inversion 
		{
			newdelta++;
		}
		recordDeltaCorrection(next, newdelta, visit, deltaCorrections, adj, guesses);
	}

	return;
}


string storyOfATree(const int n, const vector<vector<int>>& edges, const int k, const vector<vector<int>>& guesses)
{

	//adj list
	vector<vector<int>> adj(n + 1);
	for (const auto& edge : edges)
	{
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}

	//guessMap
	GuessMap guessmap(n+1);
	for (const auto& guess : guesses)
	{
		guessmap[guess[0]].insert(guess[1]);
	}

	vector<int> record(n + 1, 0); //corrections when root is 'i'
	vector<bool> visit(n + 1, false);
	//record corrections when root is '1'
	record[1] = checkGuessInRoot(1, visit, adj, guessmap);

	//record delta Correction when reroot to 'i'
	vector<int> deltaCorrections(n + 1, 0);
	::fill(visit.begin(), visit.end(), false);
	recordDeltaCorrection(1, 0, visit, deltaCorrections, adj, guessmap);

	for (int i = 1; i <= n; ++i)
	{
		record[i] = record[1] + deltaCorrections[i];
	}

	int numerator = count_if(record.begin(), record.end(), [&k](const int x) { return x >= k; });
	int denominator = n;


	//convert result to string
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

	/*
	* 34671/100000
	*/
#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}