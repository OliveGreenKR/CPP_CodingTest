#include "pch.h"
#pragma warning(disable: 4996)//printf, scanf
#include <fstream>
#include <iostream>
//#include <MyUtil.h>
#define M_PI (3.14159265358979323846)

#ifdef BACK
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000'000'000;
const int MAX_CNT = 150 +1;
int max_alp = 0, max_cop = 0;

using cost_type = int;

vector<vector<cost_type>> dp(MAX_CNT, vector<cost_type>(MAX_CNT, INF)); 


int find_min_cost(int alp, int cop, const vector<vector<int>>& problems) {

	if (alp >= max_alp && cop >= max_cop)
		return 0;

	alp = ::min(max_alp, alp);
	cop = ::min(max_cop, cop);

	if (dp[alp][cop] != INF)
		return dp[alp][cop];

	dp[alp][cop] = INF + 1;

	
	dp[alp][cop] = ::min(dp[alp][cop], find_min_cost(alp+1, cop, problems) + 1);
	dp[alp][cop] = ::min(dp[alp][cop], find_min_cost(alp, cop+1, problems) + 1);

	//problem :  [alp_req, cop_req, alp_rwd, cop_rwd, cost]
	for (auto it = problems.begin(); it != problems.end(); ++it) {
		if ((*it)[0] <= alp && (*it)[1] <= cop)
			dp[alp][cop] = ::min( dp[alp][cop], find_min_cost(alp + (*it)[2], cop + (*it)[3], problems) + (*it)[4]);
	}

	return dp[alp][cop];
}

int solution(int alp, int cop, vector<vector<int>> problems) {

	max_alp = (*::max_element(problems.begin(), problems.end(), [](auto& A, auto& B) {
		return A[0] < B[0];  }))[0];
	max_cop = (*::max_element(problems.begin(), problems.end(), [](auto& A, auto& B) {
		return A[1] < B[1];  }))[1];

	return find_min_cost(alp, cop, problems);
}

#endif 

#include <iostream>

int main() {
	//vector<vector<int>> problems = { {10,15,2,1,2},{20,20,3,3,4} };
	vector<vector<int>> problems = { {0, 0, 2, 1, 2},{4, 5, 3, 1, 2},{4, 11, 4, 0, 2},{10, 4, 0, 4, 2} };
	cout << solution(0, 0, problems);
}