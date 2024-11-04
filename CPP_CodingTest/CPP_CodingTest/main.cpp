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
	//입체 평면의 표면적 계산하기

	//3D 좌표는 (i,j,A[[i][j])
	
	//최소길이는 1 이므로
	//전체 도형의 2면적의 표면적은 고정 (H*W)
		//측면 표면적만 계산
			//각셀의 측면을 인접셀의 높이와 비하여 노출된 부분만 계산.

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


