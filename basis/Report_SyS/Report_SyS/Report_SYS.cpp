#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//자신의 신고결과에 대한  정치처리결과를 받은 횟수를 리턴(k이상의 신고를 한 경우의 수)

//신고자가 신고한 아이디를 알아야한다
//각 아이디가 몇번 신고당했는지 알아햐한다.
// 정치 처리 받은 아이디를 각 신고자가 신고한 아이디에서 검사해서 카운트 해야한다...


vector<int> MakeReportData(const vector<string>& id_list, const vector<string>& truereport, int k)
{
    vector<int> reportdata(id_list.size(), 0);
    vector<int> answer;

    //쪼개서 아이디별로 리포트 시스템 관리
    for (auto it = truereport.begin(); it != truereport.end(); ++it)
    {
        string ownerid = "";
        string ownerreport = "";

        string tmp = *it;

        size_t offset = tmp.find(" ");
        ownerid = tmp.substr(0, offset-1);
        ownerreport = tmp.substr(offset+1);

        for (auto i = 0 ;  i<id_list.size();  i++)
        {
            if( id_list[i] == ownerreport)
            {  
                //id_list의 순서에 맞춰 id가 신고받은 횟수를 저장
                reportdata[i]++;
            }
        }
    }

    for(int i = 0 ;  i<reportdata.size(); i++)
    {
        if(reportdata[i]>=k) //정지메일대상
        {
            for (auto it = truereport.begin(); it != truereport.end(); ++it)
            {
                string ownerid = "";
                string ownerreport = "";

                string tmp = *it;

                size_t offset = tmp.find(" ");
                ownerreport = tmp.substr(offset + 1);
                ownerid = tmp.substr(0, offset - 1);

                if (ownerreport == id_list[i])
                {

                }
            }

        }
    }


    return answer; 
}

//중복 제거 한 report반환
vector<string> GetTrueReportVector(const vector<string>& report)
{
    vector<string> truereport;
    for (auto it = report.begin(); it != report.end(); ++it)
    {
       //중복이 아니면
        if(count(it, report.end(),*it) < 2)
        {
            truereport.push_back(*it);
        }
    }
    return truereport;;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    vector<int> answer;
    
    vector<string> truereport = GetTrueReportVector(report);
    answer = MakeReportData(id_list, truereport, k);
    return answer;
}

#if 1
int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    solution(id_list, report, 2);

    return 0;

}
#endif // 0
