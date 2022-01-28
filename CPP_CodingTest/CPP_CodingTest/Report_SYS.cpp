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

// ���ڿ� �ɰ��� ������ ����
auto MakeReportSys(vector<string>&id_list, vector<string>&truereport)
{

    //�˻��ؼ� id ã����
    //������ġ�� 0? ==> �ڿ��� �Ű��� id��
    //������ġ�� 0x ==> �ڱ� �Ű���� ȸ�� ++

    vector<ReportSYS> reportdata;
    for (int i = 0; i < id_list.size(); ++i)
    {
        ReportSYS tmpsys;

        //���캼 id
        string ownerid = id_list[i];
        //�Ű��ڰ� �Ű��� ids
        vector<string> tmpstr;
        //ownerid�� �Ű���� ȸ��
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
                //ownerid�� �Ű����
                cnt++;
            }
            else//ownerid�� �Ű���
            {
                tmpstr.push_back(truereport[j].substr(split + 1));
            }
        }
        //�� ����
        tmpsys._cnt = cnt;
        tmpsys._targetids = tmpstr;
        reportdata.push_back(tmpsys);
    }

    return reportdata;
}

//�������� �ο� ���ϰ� �̸� �Ű��� �ο��鿡�� ���� Ƚ�� ī��Ʈ���ؾ���
auto GetAnswer(const vector<ReportSYS>&reportdata, const vector<string> id_list, int k)
{
    vector<int> answer(id_list.size(), 0);

    for (auto it = reportdata.begin(); it != reportdata.end(); ++it)
    {
        int cnt = it->_cnt;

        int idx = it - reportdata.begin();
        string ownerid = id_list[idx]; //�Ű��� id

        if (cnt >= k)//�Ű��ڴ� ����ó�� ���
        {

            //�Ű��ڸ� �Ű��� ��� ã��
            for (auto it = reportdata.begin(); it != reportdata.end(); ++it)
            {
                vector<string> targetids = it->_targetids; //�Ű���id��
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

//�ߺ� ���� �� report��ȯ
vector<string> GetTrueReportVector(const vector<string>&report)
{
    vector<string> truereport;
    for (auto it = report.begin(); it != report.end(); ++it)
    {
        //�ߺ��� �ƴϸ�
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
