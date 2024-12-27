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


int recordSubSum(int now, const vector<int>& num, const vector<vector<int>>& links, vector<int>& record)
{
    const int n = num.size();
    if (now < 0 || now >= n)
        return 0;

    int result = num[now];

    result += recordSubSum(links[now][0], num, links, record)
        + recordSubSum(links[now][1], num, links, record);

    //record
    record[now] = result;
    return result;
}

//check is splitable to k groups with MAX value 'm'
bool isSplitable(const vector<int>& subSums, int k, int m)
{

}


int solution(int k, vector<int> num, vector<vector<int>> links) {

    const int n = num.size();

    //subtree�� ������ ���
    vector<int> subSums(n);
    recordSubSum(0, num, links, subSums);

    //find M binarysearch

    return 0;
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