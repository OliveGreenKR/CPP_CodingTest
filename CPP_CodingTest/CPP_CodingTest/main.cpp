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
	
int solution(vector<vector<int>> triangle) {

    vector<vector<int>> dp(triangle);
    //dp[i][j] = tri[i][j]���� ����� �ִ� ������
    //dp[i][j] = ::max(dp[i-1][j],dp[i-1][j-1]) + tri[i][j]

    // Fill DP table
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {  // Leftmost edge - can only come from above
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if (j == i)
            {  // Rightmost edge - can only come from left-above
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else
            {  // Middle positions - can come from either above or left-above
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }

    // Find maximum value in the last row
    return *max_element(dp[triangle.size() - 1].begin(),
                        dp[triangle.size() - 1].end());
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