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

using cost_type = int;

vector<vector<cost_type>> dp(MAX_CNT, vector<cost_type>(MAX_CNT, INF)); //dp[alp][cop]의 최단시간.

//problem :  [alp_req, cop_req, alp_rwd, cop_rwd, cost]
int find_min_cost(const int alp, const int cop, cost_type cost, const vector<vector<int>>& problems) {

	static vector<bool> pass_problem(problems.size(), false);

	if (alp >= max_alp && cop >= max_cop)
		return dp[max_alp][max_cop] = ::min(cost, dp[max_alp][max_cop]);

	if (dp[alp][cop] <= cost)
		return INF;

	dp[alp][cop] = cost;

	for (auto it = problems.begin(); it != problems.end(); ++it) {
		if (pass_problem[it - problems.begin()] != true) {
			cost_type next_cost = cost;
			//필요치 까지 공부하기
			next_cost += (*it)[0] - alp > 0 ? (*it)[0] - alp : 0;
			next_cost += (*it)[1] - cop > 0 ? (*it)[1] - cop : 0;
			int next_alp = ::max((*it)[0], alp);
			int next_cop = ::max((*it)[1], cop);
			//문제 안풀기
			pass_problem[it - problems.begin()] = true;
			dp[next_alp][next_cop] = ::min(find_min_cost(next_alp, next_cop, next_cost, problems),
				dp[next_alp][next_cop]);
			pass_problem[it - problems.begin()] = false;
			//문제 풀기
			next_alp = ::min(next_alp + (*it)[2], max_alp);
			next_cop = ::min(next_cop + (*it)[3], max_cop);
			next_cost += (*it)[4];
			dp[next_alp][next_cop] = ::min(find_min_cost(next_alp, next_cop, next_cost, problems),
				dp[next_alp][next_cop]);
		}
	}
}

int solution(int alp, int cop, vector<vector<int>> problems) {

	::sort(problems.begin(), problems.end(), [](auto& A, auto& B) { return A[0] + A[1] < B[0] + B[1]; });

	max_alp = (*::max_element(problems.begin(), problems.end(), [](auto& A, auto& B) {
		return A[0] < B[0];  }))[0];
	max_cop = (*::max_element(problems.begin(), problems.end(), [](auto& A, auto& B) {
		return A[1] < B[1];  }))[1];

	find_min_cost(alp, cop, 0, problems);

	return dp[max_alp][max_cop];
}

#endif 

#include <iostream>

int main() {
	//vector<vector<int>> problems = { {10,15,2,1,2},{20,20,3,3,4} };
	vector<vector<int>> problems = { {0, 0, 2, 1, 2},{4, 5, 3, 1, 2},{4, 11, 4, 0, 2},{10, 4, 0, 4, 2} };
	cout << solution(0, 0, problems);
}