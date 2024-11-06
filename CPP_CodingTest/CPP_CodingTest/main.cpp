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

void almostSorted(vector<int> arr) {
    //ascending order sort
        //available operations
            //1.swap 2 elements [higher opportunity]
            //2.reverse 1 sub-segment

        //print 'yes' if arr is already sorted or can be sorted by running only 1 operations.
            //1. -> print swapped indices.
            //2. -> print sub segment's begin,end indices
        //otherwise, print 'no'

    int n = arr.size();
    int start = -1, end = -1;

    //record unsorted part
    for (int i = 0; i < n - 1; i++)
    {

        //find inversions
        if (arr[i] > arr[i + 1])
        {
            if (start == -1)
            {
                start = i;
            }
            end = i + 1;
        }
    }

    //already sorted
    if (start == -1)
    {
        cout << "yes" << endl;
        return;
    }

    //check swap
    swap(arr[start], arr[end]);
    bool isSwapSorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            isSwapSorted = false;
            break;
        }
    }

    if (isSwapSorted)
    {
        cout << "yes" << endl;
        cout << "swap " << start + 1 << " " << end + 1 << endl;
        return;
    }
    //check reverse
    swap(arr[start], arr[end]);
    reverse(arr.begin() + start, arr.begin() + end + 1);
    bool isReverseSorted = true;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            isReverseSorted = false;
            break;
        }
    }

    if (isReverseSorted)
    {
        cout << "yes" << endl;
        cout << "reverse " << start + 1 << " " << end + 1 << endl;
    }
    else
    {
        cout << "no" << endl;
    }

}

int main() {
    vector<int> arr = { 43,65,1,98,99,101 };

    almostSorted(arr);
}


