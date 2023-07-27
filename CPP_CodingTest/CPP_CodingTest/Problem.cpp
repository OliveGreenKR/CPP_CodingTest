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
const int INF = 10001;
const int MAX_CNT = 150 +1;

int max_alp = 0, max_cop = 0;
vector<vector<int>> dp(MAX_CNT, vector<int>(MAX_CNT, INF)); //dp[alp][cop]의 최단시간.

void SolvingProblems(int alp, int cop, const vector<vector<int>>& problems) {
	//problem[alp_req, cop_req, alp_rwd, cop_rwd. cost]
	for (auto& problem : problems) {
		int al_req = problem[0]; int co_req = problem[1];;
		int pre_alp = alp - problem[2];
		int pre_cop = cop = problem[3];
		int cost = problem[4];
		if (pre_alp >= al_req && pre_cop >= co_req) {
	/*		alp = ::min(alp, max_alp);
			cop = ::min(cop, max_cop)*/;
			dp[alp][cop] = ::min(dp[alp][cop], dp[pre_alp][pre_cop] + cost);
		}
	}
}
int solution(int alp, int cop, vector<vector<int>> problems) {
	max_alp = (*::max_element(problems.begin(), problems.end(), [](auto& A, auto& B) {
		return A[0] < B[0];  }))[0];
	max_cop = (*::max_element(problems.begin(), problems.end(), [](auto& A, auto& B) {
		return A[1] < B[1];  }))[1];

	dp[alp][cop] = 0;

	for (int a = alp; a <= max_alp ; ++a) {
		for (int b = cop; b <= max_cop ; ++b) {
			//공부하기
			if (a >= 1)
				dp[a][b] = ::min(dp[a-1][b] + 1, dp[a][b]);
			if (b >= 1)
				dp[a][b] = ::min(dp[a][b-1] + 1, dp[a][b]);
			//문제풀기
			SolvingProblems(a, b, problems);
		}
	}

	return dp[max_alp][max_cop];
}

#endif 

#include <iostream>

int main() {
	//vector<vector<int>> problems = { {10,15,2,1,2},{20,20,3,3,4} };
	vector<vector<int>> problems = { {0, 0, 2, 1, 2},{4, 5, 3, 1, 2},{4, 11, 4, 0, 2},{10, 4, 0, 4, 2} };
	cout << solution(0, 0, problems);
}