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

int circularRange(int start, int end, int value) {
    int range = end - start + 1;
    return start + (value - start) % range;
}

int maxMin(int k, vector<int> arr) {
    //k���� ���ҷ� ������ �κй迭���� �ִ�-�ּҰ��� ������ �ּڰ�.
    set<int> dtas(arr);
    if(dtas.size() > 2)
        return dtas[0] - dtas[1];
    else
    {
        return 0;
    }
}

int main() {

    //1...2,3,,4,5,,,6,7,,,en
    // 1...2
    // 1..2,3,, 4
}