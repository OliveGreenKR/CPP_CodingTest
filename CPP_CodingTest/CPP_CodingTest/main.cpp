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

#define OUT

using namespace std;


pair<int, int> findOverlapRange(int a, int b, int c, int d) {
    if (a <= d && b >= c) //overlap
    {
        // Calculate the overlapping range
        int overlapStart = max(a, c);
        int overlapEnd = min(b, d);
        return { overlapStart, overlapEnd };
    }
    else
    {
        // No overlap
        return { -1, -1 };
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string highestValuePalindrome(string s, int n, int k) {

    int changes = 0;
    vector<bool> modified(n, false);

    // Palindrome이 가능한지?

    //변경 가능한지 확인
       //이미 회문
       //변경 시 회문 -> 변경해야하는 index

       //회문 판단 시, 일단 최소 변경으로 최대값으로 변경.
           //회문을 첫 문장부터 판단하면서 큰 값으로 맞춤

       //변경 가능 값이 남으면, 추가 변경 후 return.


    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            //to make Bigger Palindrome
            if (s[i] > s[n - i - 1])
            {
                s[n - i - 1] = s[i];
            }
            else
            {
                s[i] = s[n - i - 1];
            }
            // store modified
            modified[i] = true;
            k--;
        }
    }

    if (k < 0)
        return "-1";

    for (int i = 0; i < n / 2; i++)
    {

        if (k <= 0)
            break;

        if (s[i] != '9')
        {
            //already modified -> 1 
            if (modified[i] && k >= 1)
            {
                s[i] = s[n - i - 1] = '9';
                k--;
            }
            //new -> 2
            else if (!modified[i] && k >= 2)
            {
                s[i] = s[n - i - 1] = '9';
                k -= 2;
            }
        }
    }

    //when odd, can modify middle char 
    if (n % 2 == 1 && k > 0)
    {
        s[n / 2] = '9';
    }

    return s;
}


long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);  // 배열은 1부터 시작하기 때문에 n+1 크기로 선언

    // 각 구간에 대해 값을 더하고 빼기
    for (const auto& q : queries)
    {
        int a = q[0] - 1;  // 0-based 인덱스
        int b = q[1];      // b+1에 값을 빼야 하므로 그대로 사용
        int k = q[2];

        arr[a] += k;       // 시작점에 k를 더함
        if (b < n)
        {
            arr[b] -= k;   // 끝 다음에 k를 뺌 (배열의 범위를 벗어나지 않으면)
        }
    }

    // 배열에서 누적합을 계산하며 최대값 찾기
    long max_value = 0;
    long current_value = 0;
    for (int i = 0; i < n; i++)
    {
        current_value += arr[i];
        max_value = max(max_value, current_value);
    }

    return max_value;
}

int main() {
    int n = 5;
    vector<vector<int>> queries = {
        {1, 2, 100},
        {2, 5, 100},
        {3, 4, 100}
    };

    cout << "Maximum value after manipulation: " << arrayManipulation(n, queries) << endl;

    return 0;
}


int main() {
    
    return 0;
}


int main() {

}