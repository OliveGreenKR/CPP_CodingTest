#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <unordered_map>

using namespace std;

void minimumBribes(vector<int> q) {
    int n = q.size();
    int brideSum = 0;
    for (int now = n - 1; now >= 0; now--)
    {
        int expectedPos = q[now];
        int initPos = now + 1;

        if (expectedPos - initPos > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }

        for (int possiblePos = std::max(0, expectedPos - 2); possiblePos < now; possiblePos++)
        {
            //through me
            if (q[possiblePos] > expectedPos)
                brideSum++;
        }
    }
    cout << brideSum << endl;
}

int main() {

    
}