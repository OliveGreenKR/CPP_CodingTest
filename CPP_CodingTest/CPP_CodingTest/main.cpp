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
#include <cmath>
#include <limits>

#define OUT

using namespace std;


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    //�־��� cities ��
    //Union-Find �� ����

    //������� �� ������ ���� : S 

    //�� ���տ���
        //�ּ� ������ �Ǽ� ���� => 1��
        //�ֵ� ���� �Ǽ� ���� => (i���� ���Ұ��� -1) = ki

    //�Ǽ��� ���� ���� road
    //�Ǽ��� ���� ���� city.

    //road  -> [sum(ki)]
    //lib -> [S]

    //road <=> lib ��  1:1 ��ȯ ����. 
    //��, road + lib �� �׻� ���� ���� �����ؾ���
        //�ٵ� lib�� �׻� �ּ� ������ �����ؾ��ϴ� 1:1�� ��ȯ�� �̵��̶��, ���� �������� ���ø��� ����� ���̵�.
        //ó������ ����ó�� ���� ( c_road >= clib )-> return c_lib*n;
    
    
    //�ش� ���ǿ��� (c_lib * lib + c_road * road) �� �ּ� ����� ã�� �Լ�
}

int main() {

}