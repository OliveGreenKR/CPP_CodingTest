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
	


// Check if it's possible to transport required amount of gold and silver within given time
bool isPossible(const long long time, int gold, int silver, const vector<int>& g,
                const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    const int n = g.size();

    //��, �� ��� ������ �ִ븦 �ű�ٰ� ����
       // ��ΰ� �����ַ� �� ��, ��ΰ� �� ���ַ� �� �� 

    long long totalGold = 0;    // Total transportable gold
    long long totalSilver = 0;  // Total transportable silver
    long long totalMineral = 0; // Total transportable minerals (gold + silver)

    for (int i = 0; i < n; i++)
    {
        //��� �ð� =  t + (���Ƚ��-1) * 2t  (Ƚ�� >=1)
        //���Ƚ�� =  floor((totalT - t)/2t + 1)
        long long rounds = 0;
        if (time >= t[i])
        {
            rounds = (time - t[i]) / (2 * t[i]) + 1;
        }

        const long long maxGold = min(1LL * w[i] * rounds, 1LL * g[i]);
        const long long maxSilver = min(1LL * w[i] * rounds, 1LL * s[i]);
        long long maxWeight = min(1LL * w[i] * rounds, 1LL * g[i] + s[i]);

        totalGold += maxGold;
        totalSilver += maxSilver;
        totalMineral += maxWeight;
    }

    // �ΰ��� ������ ��, �� ���� �� �䱸������ �Ѱ�, ��� ȭ������ ��� �䱸 ȭ������ ������ ����
    return  (totalGold >= gold) && (totalSilver >= silver) && (totalMineral >= ((long long)gold + silver));
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    //���� ���� N <= 1e5 -> NlogN ���Ϸ�

    //get lower_bound possible time.
    long long left = 0;
    long long right = 1e9 * 4LL * 1e5; //�Ѱ� ��� �ð�

    //binary search
    while (left < right)
    {
        long long mid = (left + right) / 2;
        if (isPossible(mid, a, b, g, s, w, t))
        {
            //smaller mid
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
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
    cout << solution(10, 10, { 100 }, { 100 }, { 7 }, { 10 });

#pragma region CloseFile 
	fin.close(); // �Է� ���� �ݱ�
	fout.close(); // ��� ���� �ݱ�
#pragma endregion
	return 0;
}