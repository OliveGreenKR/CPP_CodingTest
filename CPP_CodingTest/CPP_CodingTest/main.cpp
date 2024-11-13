#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>

#define OUT

using namespace std;

long long minimumLoss(vector<long long>& price) {
    int n = price.size();

    //record index first
    unordered_map<long long, int> indexOf;
    for (int i = 0; i < n; i++)
    {
        indexOf[price[i]] = i;
    }

    //sort Price
    sort(price.begin(), price.end());

    long long minLoss = LLONG_MAX;
    //find Min Diff 
    for (int i = 1; i < n; i++)
    {
        long long diff = price[i] - price[i - 1];
        if (diff < minLoss && indexOf[price[i]] < indexOf[price[i - 1]])
        {
            minLoss = diff;
        }
    }

    return minLoss;
}
int main() {

    ifstream inputFile("./input.txt"); // �Է� ���� ����
    ofstream outputFile("./output.txt"); // ��� ���� ����
    if (!inputFile)
    {
        cerr << "Unable to open input file";
        return 1; // �Է� ������ �� �� ������ ���α׷� ����
    }
    if (!outputFile)
    {
        cerr << "Unable to open output file";
        return 1; // ��� ������ �� �� ������ ���α׷� ����
    }


    //inputFile >> l >> r; // �� �������� l�� r �б�
    
    vector<long long> price = { 20, 7, 8, 2, 5 };
    cout << minimumLoss(price);
    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
    
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
    

    //8,705,701,581,298,678
    return 0;
}

//int main2()
//{
//}
