#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//�ڽ��� �Ű����� ����  ��ġó������� ���� Ƚ���� ����(k�̻��� �Ű� �� ����� ��)

//�Ű��ڰ� �Ű��� ���̵� �˾ƾ��Ѵ�
//�� ���̵� ��� �Ű���ߴ��� �˾����Ѵ�.
// ��ġ ó�� ���� ���̵� �� �Ű��ڰ� �Ű��� ���̵𿡼� �˻��ؼ� ī��Ʈ �ؾ��Ѵ�...


vector<int> MakeReportData(const vector<string>& id_list, const vector<string>& truereport, int k)
{
    vector<int> reportdata(id_list.size(), 0);
    vector<int> answer;

    //�ɰ��� ���̵𺰷� ����Ʈ �ý��� ����
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
                //id_list�� ������ ���� id�� �Ű���� Ƚ���� ����
                reportdata[i]++;
            }
        }
    }

    for(int i = 0 ;  i<reportdata.size(); i++)
    {
        if(reportdata[i]>=k) //�������ϴ��
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

//�ߺ� ���� �� report��ȯ
vector<string> GetTrueReportVector(const vector<string>& report)
{
    vector<string> truereport;
    for (auto it = report.begin(); it != report.end(); ++it)
    {
       //�ߺ��� �ƴϸ�
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
