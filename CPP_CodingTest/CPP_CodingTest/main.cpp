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

long long gridlandMetro(int n, const int& m, int k, vector<vector<int>> track) {

    //find opencells
    sort(track.begin(), track.end());
    vector<Track> trackRecord;
    int currentRow = track[0][0];
    long long trackedCell = 0;
    for (const auto& trackInfo : track)
    {
        const int row = trackInfo[0];
        const int from = trackInfo[1];
        const int to = trackInfo[2];

        if (row != currentRow )
        {
            for (const auto& record : trackRecord)
            {
                trackedCell += record.right - record.left + 1;
            }
            trackRecord.clear();
            currentRow = row;
        }

        Track NewTrack(from, to);
        
        bool isMerged = false;
        for (Track& record : trackRecord)
        {
            isMerged = record.TryMerge(NewTrack);
            if (isMerged)
                break;
        }
        if (isMerged == false)
        {
            trackRecord.push_back(NewTrack);
        }
    }

    for (const auto& record : trackRecord)
    {
        trackedCell += record.right - record.left + 1;
    }

    return (long long)(n) * m - trackedCell;
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
    
    int n, m, k;
    vector<vector<int>> track;

    inputFile >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int r, from, to;
        inputFile >> r >> from >> to;
        track.push_back({ r, from, to });
    }
    cout << gridlandMetro(n, m, k, track);
    //outputFile << result << "\n"; // ����� ��� ���Ͽ� ����
    
    inputFile.close(); // �Է� ���� �ݱ�
    outputFile.close(); // ��� ���� �ݱ�
    

    //8,705,701,581,298,678
    return 0;
}

//int main2()
//{
//}
