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

string encryption(string s) {

    //remove spaces
    s.erase(::remove_if(s.begin(), s.end(), ::isspace), s.end());
    //get size of row, columns
    const int L = s.length();

    const int cols = ::ceil(::sqrt(L));

    //push the string to a matrix
    vector<string> encryption(cols);
    for (int i = 0; i < cols; ++i)
    {
        int picker = i;
        //push the encryption
        while (picker < L)
        {
            encryption[i] += s[picker];
            picker += cols;
        }
    }

    //print each columns with space 
    string result;
    ostringstream oss;
    for (string ecry : encryption)
    {
        oss << ecry << " ";
    }

    result = oss.str();

    return result;
}
int main() {

}


