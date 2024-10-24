#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <locale>
#include <unordered_map>

using namespace std;

// Function to calculate circular range
int circularRange(int start, int end, int value) {
    int range = end - start + 1;
    return start + (value - start) % range;
}

// Function to check if a string is valid by removing at most one character
string isValid(string s) {
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }

    unordered_map<int, int> freqCount;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freqCount[freq[i]]++;
        }
    }

    if (freqCount.size() == 1) {
        return "YES";
    } else if (freqCount.size() == 2) {
        auto it = freqCount.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if ((c1 == 1 && (f1 - 1 == f2 || f1 - 1 == 0)) || (c2 == 1 && (f2 - 1 == f1 || f2 - 1 == 0))) {
            return "YES";
        }
    }

    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
}