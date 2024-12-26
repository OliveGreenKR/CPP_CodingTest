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

using Pos = pair<int, int>;
using Shape = vector<Pos>;

string shapeHash( Shape& shape)
{
    if (shape.size() < 1)
        return "";

    //sort
    sort(shape.begin(), shape.end());

    //serialize
    Pos coord = shape[0];
    for  ( Pos& p : shape)
    {
        p.first -= coord.first;
        p.second -= coord.second;
    }

    string hash;
    for (const Pos& p : shape)
    {
        hash += to_string(p.first) + to_string(p.second);
    }

    return hash;
}

vector<Shape> getAllShapes(vector<vector<int>>& board)
{
    const int n = board.size();
    vector<Shape> shapes;

    //get all Shapes in board
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 1)
            {
                const Shape shape = getShape(i, j, board);
                shapes.push_back(shape);
            }
        }
    }

    return shapes;
}

Shape getShape(int x, int y, vector<vector<int>>& board)
{
    const int n = board.size();
    if (x < 0 || y < 0 || x >= n || y >= n)
        return {};

    if (board[x][y] == 0)
        return {};

    static vector<int> dirX = { 1,0,-1,0 };
    static vector<int> dirY = { 0,1,0,-1 };

    Shape result;
    //visit
    board[x][y] = 0;
    result.push_back({ x,y });

    //add next
    for (int i = 0; i < 4; ++i)
    {
        const Shape other = getShape(x + dirX[i], y + dirX[i], board);
        result.insert(result.end(),other.begin(),other.end());
    }

    return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {

    vector<Shape> boardShapes = getAllShapes(game_board);
    vector<Shape> tableShapes = getAllShapes(table);

    unordered_map<string, int> shapeSize;  //shape , size
    unordered_map<string, int> tableMap; //shape , cnt
    unordered_map<string, int> boardMap; //shape , cnt

    for (Shape& shape : boardShapes)
    {
        string key = shapeHash(shape);
        int size = shape.size();

        shapeSize[key] = size;
        boardMap[key]++;
    }

    for (Shape& shape : tableShapes)
    {
        string key = shapeHash(shape);
        int size = shape.size();

        shapeSize[key] = size;
        tableMap[key]++;
    }

    for (const auto it : boardMap)
    {
        if()
    }

}


int main() {
    string infile = "./input.txt";
    string outfile = "./output.txt";
#pragma region OpenFile
    ifstream fin(infile);
    ofstream fout(outfile);
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