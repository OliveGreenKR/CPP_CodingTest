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
#include <fstream> // 파일 입출력을 위한 헤더 추가
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

int binarySearch()
{
    int left = 1;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        //가장 큰 집합의 크기가 mid 이하일때의 그룹 개수
        int gcount = findMinGroups(mid);

        //k 초과의 그룹 생성 가능 -> 집합 크기 증가
        if (gcount > k)
            left = mid + 1;

        //k 이하의 그룹 생성 가능 -> 집합 크기 감소
        if (gcount <= k)
            right = mid; //mid값을 포함해야 함
    }

    return left;
}


//최대 크기가 m이하인 그룹의 최소 개수
int findMinGroups(int m, Node* root)
{
    int gcount = 1; //기본 그룹 수 
    int now = root->size;

    //m이하의 서브트리
    if (now <= m)
        return gcount;

    /* Case 1 : 둘 다 분리해도 불가 -> 'm이 너무 작다'  ->
       이진탐색 시 'k보다 많은 그룹'이 나와야 m을 증가시킴
  */
    return INF;

    /*Case 2 : 더 큰 자식 하나만 분리해도 가능*/
    gcount += findMinGroups(int m, root->largerChild);

    /*Case 3 : 둘 다 분리해야 가능*/
    gcount += findMinGroups(int m, root->left)
        + findMinGroups(int m, root->right);


    //최대 INF를 넘지 않도록 결과 리턴.
    return min(INF, gcount);
}

int solution(int k, vector<int> num, vector<vector<int>> links) {

    const int n = num.size();
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
        return 1; // 입력 파일을 열 수 없으면 프로그램 종료
    }
    if (!fout)
    {
        cerr << "Unable to open output file";
        return 1; // 출력 파일을 열 수 없으면 프로그램 종료
    }
#pragma endregion


#pragma region CloseFile 
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
#pragma endregion
    return 0;
}