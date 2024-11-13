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

int pairs(int k, vector<int> arr) {
    unordered_set<int> elementSet;

    for (const int elm : arr)
    {
        elementSet.insert(elm);
    }

    int countPairs = 0;
    for (const int e : arr)
    {
        if (elementSet.find(e - k) != elementSet.end())
        {
            countPairs++;
        }
        if (elementSet.find(e + k) != elementSet.end())
        {
            countPairs++;
        }
        elementSet.erase(e);
    }

    return countPairs;
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
    int k = 2;
    vector<int> pair = { 1,5,3,4,2 };
    cout << pairs(2, pair);

    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
    
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
    

    //8,705,701,581,298,678
    return 0;
}

//int main2()
//{
//}
