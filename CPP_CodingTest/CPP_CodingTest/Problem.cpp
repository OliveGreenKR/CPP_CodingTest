#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <string>
#include <vector>
#include <exception>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {

    using int64 = long long;
    int answer = 0;

    const size_t size = queue1.size();

    queue1.reserve(2 * size);
    queue2.reserve(2 * size);

    size_t q1 = 0, q2 = 0;  //q의 시작을 가리킴.

    int64 sum1=0, sum2=0;

    for (int i = 0; i < size; ++i) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    if ((sum1 + sum2) & 1)
        return -1;

    while (sum1 != sum2) {
        try {
            if (sum1 < sum2) {
                int now = queue2[q2++];
                sum1 += now;
                sum2 -= now;
                queue1.push_back(now);
            } else {
                int now = queue1[q1++];
                sum2 += now;
                sum1 -= now;
                queue2.push_back(now);
            }
            if (q1 > size && q2 > size)
                return -1;
            answer++;
        }
        catch (exception& e) {
            return -1;
        }
    }

    return answer;
}

#endif 

#include <iostream>

int main() {

    vector<int> q1 = { 3, 2, 7, 2 };
    vector<int> q2 = { 4, 6, 5, 1 };

    cout << solution(q1, q2) << endl;
}