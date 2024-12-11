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

//check if the string is rightful  : O(N)
bool isRight(const string& str) {
    int count = 0;

    for (char c : str)
    {
        if (c == '(')
            ++count;
        else
            --count;

        if (count < 0)
            return false;
    }
    return count == 0;
}

//find smallest balaned str idx
pair<string, string> splitBalanced(const string& str)
{
    int count = 0;
    string u;

    for (int i = 0; i < str.size(); ++i)
    {
        u += str[i];
        if (str[i] == '(')
            ++count;
        else
            --count;
        if (count == 0)
            return { u,str.substr(i + 1) };
    }
    return { u,"" };
}

string solution(string p) {
    const int n = p.size();

    if (n < 1)
        return p;

    //find smallest balaned str
    auto pairs = splitBalanced(p);
    string u = pairs.first;
    string v = pairs.second;

    if (isRight(u))
    {
        return u + solution(v);
    }

    string result = "(" + solution(v) + ")";
    for (int i = 0; i < u.size(); ++i)
    {
        u[i] = u[i] == '(' ? ')' : '(';
    }

    return u + result;
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
	cout << solution({ ")(" });

#pragma region CloseFile 
	fin.close(); // �Է� ���� �ݱ�
	fout.close(); // ��� ���� �ݱ�
#pragma endregion
	return 0;
}