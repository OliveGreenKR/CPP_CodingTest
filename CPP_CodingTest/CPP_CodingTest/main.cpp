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
#include <fstream> // 파일 입출력을 위한 헤더 추가
#include <bitset>

#define OUT

using namespace std;

class Track
{
public:
    Track(int l, int r) : left(l), right(r) {}

    int left, right;
public:
    bool TryMerge(const Track& other)
    {
        //is mergable
        if (other.left > right || other.right < left)
        {
            return false;
        }
        else
        {
            left = min(left, other.left);
            right = max(right, other.right);
        }
        return true;
    }
};

int gridlandMetro(int n, const int& m, int k, vector<vector<int>> track) {

    //find opencells
    vector <vector<Track>> tracked(n);

    for (const auto& trackInfo : track)
    {
        const int row = trackInfo[0]-1;
        const int from = trackInfo[1]-1;
        const int to = trackInfo[2]-1;

        Track NewTrack(from, to);
        
        bool isMerged = false;
        for (Track& record : tracked[row])
        {
            isMerged = record.TryMerge(NewTrack);
            if (isMerged)
                break;
        }
        if (isMerged == false)
        {
            tracked[row].push_back(NewTrack);
        }
    }

    //
    int trackedCell = 0;
    for (const auto& recordVec : tracked)
    {
        for (const Track& record : recordVec)
        {
            trackedCell += (record.right - record.left)+1;
        }
    }

    return n * m - trackedCell;
}


int main2() {

    ifstream inputFile("./input.txt"); // 입력 파일 열기
    ofstream outputFile("./output.txt"); // 출력 파일 열기
    if (!inputFile)
    {
        cerr << "Unable to open input file";
        return 1; // 입력 파일을 열 수 없으면 프로그램 종료
    }
    if (!outputFile)
    {
        cerr << "Unable to open output file";
        return 1; // 출력 파일을 열 수 없으면 프로그램 종료
    }


    //inputFile >> l >> r; // 각 쿼리에서 l과 r 읽기
    //outputFile << result << "\n"; // 결과를 출력 파일에 쓰기
    
    inputFile.close(); // 입력 파일 닫기
    outputFile.close(); // 출력 파일 닫기

    return 0;
}

int main()
{
}
