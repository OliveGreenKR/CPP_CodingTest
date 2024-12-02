#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <unordered_map>
#include <unordered_set>
#include <numeric> //gcd
#include <deque>
#include <math.h>
#include <sstream>
#include <cmath>
#include <fstream> // 파일 입출력을 위한 헤더 추가
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>

#define OUT

using namespace std;

const double HOUR_ANGLE_PER_SEC = 360.0 / (12 * 3600);   // Hour hand
const double MIN_ANGLE_PER_SEC = 360.0 / 3600;           // Minute hand
const double SEC_ANGLE_PER_SEC = 360.0 / 60;

int timeToSeconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}


// Get angles for each hand
double getHourAngle(int seconds) {
    return seconds * HOUR_ANGLE_PER_SEC;
}

double getMinuteAngle(int seconds) {
    return seconds * MIN_ANGLE_PER_SEC;
}

double getSecondAngle(int seconds) {
    return seconds * SEC_ANGLE_PER_SEC;
}

bool isEqual(double angle1, double angle2) {
    const double EPSILON = 0.00001;
    double diff = fabs(angle1 - angle2);
    return diff < EPSILON || fabs(360 - diff) < EPSILON;
}

// Normalize angle to [0, 360)
double normalizeAngle(double angle) {
    angle = fmod(angle, 360.0);
    if (angle < 0) angle += 360.0;
    return angle;
}

// Check if hands will overlap between two consecutive seconds
bool willOverlap(double curr_angle1, double next_angle1,
                 double curr_angle2, double next_angle2) {
    // Normalize angles
    curr_angle1 = normalizeAngle(curr_angle1);
    next_angle1 = normalizeAngle(next_angle1);
    curr_angle2 = normalizeAngle(curr_angle2);
    next_angle2 = normalizeAngle(next_angle2);

    // Handle case where angles cross 0/360 boundary
    if (next_angle1 < curr_angle1) next_angle1 += 360.0;
    if (next_angle2 < curr_angle2) next_angle2 += 360.0;

    // Check for exact match at start
    const double EPSILON = 0.000001;
    if (fabs(curr_angle1 - curr_angle2) < EPSILON) return true;

    // Check for crossing
    double angle_diff_start = curr_angle1 - curr_angle2;
    double angle_diff_end = next_angle1 - next_angle2;

    return (angle_diff_start * angle_diff_end <= 0);
}


int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int start_sec = timeToSeconds(h1, m1, s1);
    int end_sec = timeToSeconds(h2, m2, s2);

    int count = 0;

    for (int curr_sec = start_sec; curr_sec < end_sec; curr_sec++)
    {
        // Calculate current and next angles
        double curr_hour = getHourAngle(curr_sec);
        double curr_min = getMinuteAngle(curr_sec);
        double curr_sec_angle = getSecondAngle(curr_sec);

        double next_hour = getHourAngle(curr_sec + 1);
        double next_min = getMinuteAngle(curr_sec + 1);
        double next_sec_angle = getSecondAngle(curr_sec + 1);

        // Check overlaps with second hand
        bool hour_overlap = willOverlap(curr_sec_angle, next_sec_angle,
                                        curr_hour, next_hour);
        bool min_overlap = willOverlap(curr_sec_angle, next_sec_angle,
                                       curr_min, next_min);

        // Count when second hand overlaps with either hour or minute hand
        if (hour_overlap || min_overlap)
        {
            count++;
        }
    }

    return count;
}

int main() {
	ifstream fin("./input.txt"); // 입력 파일 열기
	ofstream fout("./output.txt"); // 출력 파일 열기
#pragma region OpenFile
	if (!fin)
	{
		cerr << "Unable to open input file";
		return 1; // 입력 파일을 열 수 없으면 프로그램 종료
	}
	if (!fout)
	{
		cerr << "Unable to open output file";
		return 1; // 출력 파일을 열 수 없으면 프로그램 종료
	}
#pragma endregion
	
#pragma region CloseFile 
	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
#pragma endregion
	return 0;
}


/*
	67/100
	21/100
	1/1
	0/1
	87/100
	*/

	/* [input2]
	19/50
	1/1
	217/250
	0/1
	67/1000
	*/

	/*
	* 34671/100000
	*/