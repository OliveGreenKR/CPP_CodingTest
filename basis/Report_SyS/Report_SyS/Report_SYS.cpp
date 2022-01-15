#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//처리결과를 받은 횟수를 리턴(k이상의 신고를 한 경우의 수)

//아이디리스트에서 각 한개와 피신고자를 리포트("신고자 신고한id" 형태)에서 비교해서 카운트
    // 한유저가 같은 유저를 여러번 신고한 경우는 1번으로 처리
    //신고한 내용 취합 후 마지막에 정지메일 발송.

//레포트에서 신고를 받은id iterator
auto GetReporterIterator(const vector<string>& report)
{
    for (auto it = report.begin(); it != report.end(); ++it)
    {
        // 공백찾음
        if (*it == " ")
        {
            ++it;
            return it;
        }
    }
    return report.end(); //잘못된 문자열
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    //id_list의 순서대로 자신이 신고한 아이디중에 2회이상 신고당한 사람의 수를 push_back
    vector<int> answer;
    vector<int> totalreported; // 아이디 리스트의 순서대로 신고받은 총 회수  



    //id_list하나씩 검사
    for (auto it = id_list.begin(); it != id_list.end(); ++it)
    {
        int cnt = count(id_list.begin(), id_list.end(), *it);
        totalreported.push_back(cnt);
    }

    return answer;
}