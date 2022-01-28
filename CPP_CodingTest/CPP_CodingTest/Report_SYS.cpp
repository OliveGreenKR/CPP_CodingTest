#include "pch.h"
#if 0
include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ReportSYS
{
public:
    int _cnt = 0;
    vector<string> _targetids;
};

// 문자열 쪼개서 나누어 저장
auto MakeReportSys(vector<string>&id_list, vector<string>&truereport)
{

    //검색해서 id 찾으면
    //시작위치가 0? ==> 뒤에것 신고한 id로
    //시작위치가 0x ==> 자기 신고당한 회수 ++

    vector<ReportSYS> reportdata;
    for (int i = 0; i < id_list.size(); ++i)
    {
        ReportSYS tmpsys;

        //살펴볼 id
        string ownerid = id_list[i];
        //신고자가 신고한 ids
        vector<string> tmpstr;
        //ownerid가 신고당한 회수
        int cnt = 0;

        for (int j = 0; j < truereport.size(); j++)
        {
            size_t offset = truereport[j].find(ownerid);

            if (offset == string::npos)
            {
                continue;
            }
            size_t split = truereport[j].find(" ");


            if (offset != 0)
            {
                //ownerid가 신고당함
                cnt++;
            }
            else//ownerid가 신고함
            {
                tmpstr.push_back(truereport[j].substr(split + 1));
            }
        }
        //값 저장
        tmpsys._cnt = cnt;
        tmpsys._targetids = tmpstr;
        reportdata.push_back(tmpsys);
    }

    return reportdata;
}

//정지받은 인원 정하고 이를 신고한 인원들에게 메일 횟수 카운트를해야함
auto GetAnswer(const vector<ReportSYS>&reportdata, const vector<string> id_list, int k)
{
    vector<int> answer(id_list.size(), 0);

    for (auto it = reportdata.begin(); it != reportdata.end(); ++it)
    {
        int cnt = it->_cnt;

        int idx = it - reportdata.begin();
        string ownerid = id_list[idx]; //신고자 id

        if (cnt >= k)//신고자는 정지처분 대상
        {

            //신고자를 신고한 사람 찾기
            for (auto it = reportdata.begin(); it != reportdata.end(); ++it)
            {
                vector<string> targetids = it->_targetids; //신고한id들
                int i = it - reportdata.begin();

                auto foundit = find(targetids.begin(), targetids.end(), ownerid);
                if (foundit != targetids.end())
                {
                    answer[i]++;
                }
            }

        }
    }

    return answer;
}

//중복 제거 한 report반환
vector<string> GetTrueReportVector(const vector<string>&report)
{
    vector<string> truereport;
    for (auto it = report.begin(); it != report.end(); ++it)
    {
        //중복이 아니면
        if (count(it, report.end(), *it) < 2)
        {
            truereport.push_back(*it);
        }
    }
    return truereport;;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    vector<int> answer;
    vector<ReportSYS> reportdata;

    vector<string> truereport = GetTrueReportVector(report);
    reportdata = MakeReportSys(id_list, truereport);
    answer = GetAnswer(reportdata, id_list, k);
    return answer;
}

#if 1
int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    vector<int> answer = solution(id_list, report, 2);

    return 0;

}
#endif // 0

#endif // 0
