#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>

#define OUT

using namespace std;

string timeInWords(int h, int m) {

    //convert map
    const vector<string> numberWords = {
    "o' clock", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
    "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half",
    };

    auto getWord = [&numberWords](int inIdx) {
        int idx = 0;
        idx = ::min(inIdx, 60 - inIdx);

        return numberWords[idx];
        };

    ostringstream oss;
    if (m == 0)
    {
        oss << getWord(h) << " " << getWord(m);
    }
    else
    {
        string mid;
        if (m > 30)
        {
            mid = "to";
            ++h;
        }
        else
        {
            mid = "past";
        }

        string minutes = " minutes";
        if (m == 15 || m == 30 || m == 45)
            minutes = "";
        else if (m == 1)
            minutes = minutes.substr(0, 6);
        oss << getWord(m) << minutes << " " << mid << " " << getWord(h);
    }

    return oss.str();
}
int main() {
    cout << timeInWords(1, 1);
}


