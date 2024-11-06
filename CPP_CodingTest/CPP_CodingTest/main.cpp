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

float getMedian(vector<int>& count, int dataCount)
{
    const int medianCount = (dataCount + 1) / 2;
    int accumSum = 0; //accumulated sum
    int median = -1, median2 = -1;

    for (int i = 0; i < count.size(); ++i)
    {
        accumSum += count[i];
        if (median == -1 && accumSum >= medianCount)
        {
            median = i;
        }
        if (accumSum > medianCount)
        {
            median2 = i;
            break;
        }
    }

    return dataCount % 2 == 0 ? (median + median2) / 2.0f : median;
}

int activityNotifications(vector<int> expenditure, int d) {
    int n = expenditure.size();
    int notifications = 0;
    vector<int> count(201, 0); //max cost = 200

    //init sliding window
    for (int i = 0; i < d; i++)
    {
        count[expenditure[i]]++;
    }

    // move sliding window
    for (int i = d; i < n; i++)
    {
        // get median
        float median = getMedian(count, d);

        //check notification
        if (expenditure[i] >= median * 2)
        {
            notifications++;
        }

        // update window
        count[expenditure[i - d]]--;
        count[expenditure[i]]++;
    }

    return notifications;
}

int main() {
    return 0;
}
