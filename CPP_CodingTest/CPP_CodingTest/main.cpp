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

void dfs(int point, int cnt, int sb, const map<int, bool>& pointPool, vector<pair<int, int>>& record)
{
    //if smaller exists, return
    if (record[point] < make_pair(cnt, sb))
    {
        return;
    }

    //go to next in pointPool
        //cnt ++
        // sb -= pointPool[next]

}

vector<int> solution(int target) {

    map<int, bool, greater<int>> pointPool; //{ point, single - bull }

    //record points that can acquire with 1 dart.
        //sb �� '1' �ΰ��� �켱����.
            //double, tripple�� �������� �ʴ� key�� ���ؼ��� �߰�
            //s-b�� �׻� �߰� �� ǥ��


    //memozation  [point] = { dart , (minus) s-b }  -> can choose smaller
    
    //dfs


    return {dart, sumOfsb};
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

