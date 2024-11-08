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

string highestValuePalindrome(string& s, int n, int k) {
    //make largest palindrome in k changes.

    vector<int> needed(n, 0); //needed chages to make Largest palindrome

    //odd string, center record
    if (n % 2 == 1)
        needed[n / 2] = 1;

    //needed record
    for (int i = 0; i < n / 2; ++i)
    {
        int first = s[i] - '0';
        int second = s[n - i - 1] - '0';

        //already pair
        if (first == second)
        {
            needed[i] = 2;
        }
        else //not pair
        {
            s[i] = s[n - i - 1] = max(first + '0', second + '0');
            --k;
            needed[i] = 1;
        }
    }

    if (k < 0)
    {
        return "-1";
    }

    //to make large, greedy choice
    int i = 0;
    while (k > 0 && i <= n / 2)
    {
        if (k >= needed[i] && s[i] != '9')
        {
            k -= needed[i];
            s[i] = s[n - 1 - i] = '9';
        }
        ++i;
    }
    return s;

}
int main() {

    string s = "abcdefghhgfedecba";
    cout << isValid(s);
    return 0;
}
