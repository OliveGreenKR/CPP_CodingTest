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

#define OUT

using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
    const int n = x.size();
    sort(x.begin(), x.end());

    int transmitter = 0;
    auto uncoveredCity = x.begin();

    while (uncoveredCity != x.end())
    {
        //transmitter  = lower_bound( smallest uncoveredCity + k )
        //next smallest uncovered city =  
        //          upper_bound(recently installed transmitter + k)
        transmitter++;
        int nextlimit = *uncoveredCity + k;
        auto nextCity = upper_bound(uncoveredCity, x.end(), nextlimit);
  
        //there is a city can cover itself.
        if (*(nextCity-1) <= nextlimit )
        {
            nextlimit = *(--nextCity) + k;
            nextCity = upper_bound(nextCity, x.end(), nextlimit);
        }
        
        uncoveredCity = nextCity;
    }

    return transmitter;
}


int main2() {

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
    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
    
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�

    return 0;
}

int main()
{
    //vector<int> city = { 7, 2, 4, 6, 5, 9, 12, 11 };
    vector<int> city = { 9, 5, 4, 2, 6, 15, 12 };

    cout << hackerlandRadioTransmitters(city, 2);
}
