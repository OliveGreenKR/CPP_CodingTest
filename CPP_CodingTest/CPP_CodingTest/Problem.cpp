#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class RCJA {

public:

    RCJA() : _result(4, 0) {}


    string getNowTrait() {
        const string positive = "RCJA";
        const string negative = "TFMN";

        string trait;

        for (int i = 0; i < _result.size(); ++i) {
            if (_result[i] != 0)
                _result[i] > 0 ? trait += positive[i] : trait += negative[i];
            else
                trait += ::min(positive[i], negative[i]);
        }

        return trait;
    }

    void check(const string trait, const int choice) {
        string now;

        if (trait.size() != 2 || choice == 4)
            return;

        if (choice > 4)
            now = trait[1];
        else
            now = trait[0];

        const int point = ::abs(choice - 4);

        pointing(now, point);
    }

private:

    void pointing(const string trait, const int point) {
        const static std::map<std::string, int> mPositive
            = { {"R", 0 }, {"C", 1},{"J", 2}, {"A", 3}, };
        const static std::map<std::string, int> mNegative
            = { {"T", 0 }, {"F", 1},{"M", 2}, {"N", 3}, };

        auto findit = mPositive.find(trait);
        if (findit == mPositive.end()) {
            findit = mNegative.find(trait);
            if (findit != mNegative.end())
                _result[findit->second] -= point;
            else
                return;
        }
        else
            _result[findit->second] += point;
    }

private:
    vector<int> _result;
};

string solution(const vector<string> survey, const vector<int> choices) {

    RCJA test; 

    if (survey.size() != choices.size())
        throw std::runtime_error("wrong input");
        

    auto it_choice = choices.begin();
    auto it_survey = survey.begin();

    while (it_choice != choices.end()) {
        test.check(*it_survey++, *it_choice++);
    }

    string answer = test.getNowTrait();
    
    return answer;
}
#endif 

#include <iostream>

int main() {

    vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> choice = { 5, 3, 2, 7, 5 };

    cout << solution(survey, choice);

}