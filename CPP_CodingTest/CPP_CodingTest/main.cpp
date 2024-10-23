#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <unordered_map>

using namespace std;


string twoArrays(int k, vector<int> A, vector<int> B) {
    
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] + B[i] < k)
            return "NO";
    }

    return "YES";
}


int main() {

    
}