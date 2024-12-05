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
	

long long solution(int a, int b, const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    // i 도시 자원 -> 금 , 은 , 트럭
    //각 도시 트럭은 '새 도시 건설 장소' 와 i도시만 왕복 가능
    //왕복은 무한대로 가능
        //편도 소요 시간 t[i] , 최대 운반 가능 무기 w[i] - 금,은 혼합 이동 가능

    //모든 트럭은 최적운행 -> 현재 부족한 광물을 항상 최대의 무게로 운반.
        //본인 도시의 광물이 떨어지기 전까지 무조건 운반

    //가장 오래 운행하는 트럭의 운행시간을 확인해야함.


    // 운반 소요 시간 = t + 2(운반 횟수-1)t  
    //도시 개수 N <= 1e5 -> NlogN 이하로

    // 두 가지 자원을 모두 만족해야함.
        //한 가지 자원이라면 



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