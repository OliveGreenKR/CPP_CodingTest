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

using matchSet = unordered_set<string>;

inline string getHashedID(const vector<bool>& visit)
{
    string tmp;
    for (int i = 0; i <= visit.size(); ++i)
    {
        if (visit[i])
            tmp += i + '0';
    }
    return tmp;
}

bool isMatch(const string& str, const string& pattern)
{
    //diffent size 
    if (str.size() != pattern.size())
        return false;

    //compare each char
    for (int i = 0; i <= pattern.size(); ++i)
    {
        //return false when it is not wildcard and different 
        if (pattern[i] != '*' && pattern[i] != str[i])
            return false;
    }

    return true;
}

void countMatch(int current, const vector<string>& user_id, const vector<string>& banned_id,
               vector<bool>& visit, matchSet& result)
{
    //banned_id만큼 찾음
    if (current == banned_id.size())
    {
        //get Hahsed String for selected ids.
        string tmp = getHashedID(visit);
        //insert
        result.insert(tmp);
        return;
    }

    for (size_t i = 0; i < user_id.size(); i++)
    {
        if (!visit[i] && isMatch(user_id[i], banned_id[current]))
        {
            visit[i] = true;
            countMatch(current+1,user_id, banned_id, visit, result);

            //backtrack
            visit[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    const int n = user_id.size();
 
    vector<bool> visit(n, false);
    matchSet result;

    countMatch(0, user_id, banned_id, visit, result);

    return result.size();
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

