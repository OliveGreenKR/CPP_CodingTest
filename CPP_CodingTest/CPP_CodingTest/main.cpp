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
	

long long solution(int a, int b, const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    // i ���� �ڿ� -> �� , �� , Ʈ��
    //�� ���� Ʈ���� '�� ���� �Ǽ� ���' �� i���ø� �պ� ����
    //�պ��� ���Ѵ�� ����
        //�� �ҿ� �ð� t[i] , �ִ� ��� ���� ���� w[i] - ��,�� ȥ�� �̵� ����

    //��� Ʈ���� �������� -> ���� ������ ������ �׻� �ִ��� ���Է� ���.
        //���� ������ ������ �������� ������ ������ ���

    //���� ���� �����ϴ� Ʈ���� ����ð��� Ȯ���ؾ���.


    // ��� �ҿ� �ð� = t + 2(��� Ƚ��-1)t  
    //���� ���� N <= 1e5 -> NlogN ���Ϸ�

    // �� ���� �ڿ��� ��� �����ؾ���.
        //�� ���� �ڿ��̶�� 



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