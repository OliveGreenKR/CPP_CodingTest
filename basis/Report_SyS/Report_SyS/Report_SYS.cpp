#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//ó������� ���� Ƚ���� ����(k�̻��� �Ű� �� ����� ��)

//���̵𸮽�Ʈ���� �� �Ѱ��� �ǽŰ��ڸ� ����Ʈ("�Ű��� �Ű���id" ����)���� ���ؼ� ī��Ʈ
    // �������� ���� ������ ������ �Ű��� ���� 1������ ó��
    //�Ű��� ���� ���� �� �������� �������� �߼�.

//����Ʈ���� �Ű� ����id iterator
auto GetReporterIterator(const vector<string>& report)
{
    for (auto it = report.begin(); it != report.end(); ++it)
    {
        // ����ã��
        if (*it == " ")
        {
            ++it;
            return it;
        }
    }
    return report.end(); //�߸��� ���ڿ�
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    //id_list�� ������� �ڽ��� �Ű��� ���̵��߿� 2ȸ�̻� �Ű���� ����� ���� push_back
    vector<int> answer;
    vector<int> totalreported; // ���̵� ����Ʈ�� ������� �Ű���� �� ȸ��  



    //id_list�ϳ��� �˻�
    for (auto it = id_list.begin(); it != id_list.end(); ++it)
    {
        int cnt = count(id_list.begin(), id_list.end(), *it);
        totalreported.push_back(cnt);
    }

    return answer;
}