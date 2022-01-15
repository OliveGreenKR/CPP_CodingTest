#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//처리결과를 받은 횟수를 리턴(k이상의 신고를 한 경우의 수)

//아이디리스트에서 각 한개와 피신고자를 리포트("신고자 신고한id" 형태)에서 비교해서 카운트
    // 한유저가 같은 유저를 여러번 신고한 경우는 1번으로 처리
    //신고한 내용 취합 후 마지막에 정지메일 발송.

//레포트에서 신고를 한사람 추출하는 함수

vector<string> GetReporterID(vector<string>& report)
{

}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //id_list하나씩 검사
    for (auto it = id_list.begin(); it != id_list.end(); ++it)
    {

        if ()
    }
    return answer;
}