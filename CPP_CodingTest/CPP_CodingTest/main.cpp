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

int solution(vector<vector<int>> matrix_sizes) {

    const int n = matrix_sizes.size();

    //dp table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    //fill dp
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = INT32_MAX; //init


            //try all split point
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = ::min(dp[i][j],
                                 dp[i][k] + dp[k + 1][j] +
                                 matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]);
            }
        }
    }

    return dp[0][n - 1];
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