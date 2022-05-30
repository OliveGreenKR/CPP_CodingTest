#include <vector>
#include <algorithm>
#include <string>
using namespace std;

inline int getIdx(vector<string>&id_list, string& id)
{
    for (int i = 0; i<id_list.size(); i++)
        if (id_list[i]==id)
            return i;

    return -1;
}

vector<string> Delim(string&& str, string& delim)
{
    vector<string> ret;//[reporter][reportee]
    size_t pos = 0;
    while ((pos = str.find(delim)) != string::npos)
    {
        ret.push_back(str.substr(0, pos));
        str.erase(0, pos + delim.length());
    }
    ret.push_back(str);
    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer(id_list.size(),0);
    vector<int> Rcount(id_list.size(),0);                                //how many i was reported 
    vector<vector<int>> Reporters(id_list.size(),vector<int>(0));        //who str i 

    ::sort(report.begin(), report.end());
   
    int exReportee = -1;
    int exReporter = -1;
    string delim = " ";
    for (int i = 0; i<report.size(); i++)
    {
        auto log = Delim(::move(report[i]), delim);
        int reporter = getIdx(id_list,log[0]);
        int reportee = getIdx(id_list,log[1]);

        if (exReporter == reporter && exReportee == reportee)
        {
            continue;
        }
           
        Rcount[reportee]++;
        Reporters[reportee].push_back(reporter);

        exReportee = reportee;
        exReporter = reporter;
    }
  
    //count check
    for (int i = 0; i<Rcount.size(); i++)
    {
        if (Rcount[i]>=k)
        {
            for (int j = 0; j<Reporters[i].size(); j++)
            {
                answer[Reporters[i][j]]++;
            }
        }
    }

    return answer;
}
