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

int surfaceArea(vector<vector<int>> A) {
	//��ü ����� ǥ���� ����ϱ�

	//3D ��ǥ�� (i,j,A[[i][j])
	
	//�ּұ��̴� 1 �̹Ƿ�
	//��ü ������ 2������ ǥ������ ���� (H*W)
		//���� ǥ������ ���
			//������ ������ �������� ���̿� ���Ͽ� ����� �κи� ���.

    const int H = A.size();
    const int W = A[0].size();

    int totalSurfaceArea = 0;

    //Upper, Lower Side
    totalSurfaceArea += 2 * H * W;

    auto GetCellHeight = [&A, H, W](const int i, const int j)
        {
            if (i < 0 || i >= H || j < 0 || j >= W)
            {
                return 0;
            }
            else
            {
                return A[i][j];
            }
        };

    //check the Side sufaces.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            const int current = GetCellHeight(i, j);
            //North 
            totalSurfaceArea += ::max(0, current - GetCellHeight(i - 1, j));
            //East 
            totalSurfaceArea += ::max(0, current - GetCellHeight(i, j + 1));
            //South
            totalSurfaceArea += ::max(0, current - GetCellHeight(i + 1, j));
            //West 
            totalSurfaceArea += ::max(0, current - GetCellHeight(i, j - 1));
        }
    }

    return totalSurfaceArea;

}

int main() {

}


