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
#include <fstream> // ���� ������� ���� ��� �߰�
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <bitSet>


#define OUT

using namespace std;

using Pos = pair<float, float>;
using Shape = vector<Pos>;

Shape normalizeShape(const Shape& shape)
{
    //������ ��ǥ�踦 ��ġ����, ������ ã�� �� �ֵ��� �ؾ���

    return Shape();
}

vector<Shape> getAllRotateForm(Shape& shape)
{
    if (shape.size() < 1)
        return {};

    //4���� ȸ�� ���
    vector<Shape> result(4);

    //4 rotations
    for (Pos& p : shape)
    {
        int x = p.first;
        int y = p.second;

        result[0].push_back({ x,y });
        result[1].push_back({ -y,x });
        result[2].push_back({ -x,-y });
        result[3].push_back({ y,-x });
    }
    return result;
}

string shapeHash( const Shape& shape)
{
    //get 4 normalized forms
    Shape ns = normalizeShape(shape);
    vector<Shape> shapes = getAllRotateForm(ns);

    //4���� ������ hashkey���� �ϰ��� ��Ģ���� �ϳ� ���� -> 4���� ������ ��ǥ�ϴ� �ϳ��� Ű�� 
    vector<string> hashes;
    for (const Shape& s : shapes)
    {
        //hashing shape
    }

    sort(hashes.begin(), hashes.end());
    return hashes[0];
}

//find all coord in dfs
Shape getShapeDFS(int x, int y, vector<vector<int>>& board)
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
        const Shape other = getShapeDFS(x + dirX[i], y + dirY[i], board);
        result.insert(result.end(),other.begin(),other.end());
    }

    return result;
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
                const Shape shape = getShapeDFS(i, j, board);
                shapes.push_back(shape);
            }
        }
    }

    return shapes;
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

    int count = 0;
    for (const auto x : boardMap)
    {
        auto y = tableMap.find(x.first);

        if (y != tableMap.end())
        {
            int size = shapeSize[x.first];
            int num = min(x.second, y->second);
            count += size * num;
        }
    }

    return count;

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
        return 1; // �Է� ������ �� �� ������ ���α׷� ����
    }
    if (!fout)
    {
        cerr << "Unable to open output file";
        return 1; // ��� ������ �� �� ������ ���α׷� ����
    }
#pragma endregion

    vector<vector<int>> game_board = { {1, 1, 0, 0, 1, 0}, { 0, 0, 1, 0, 1, 0 }, { 0, 1, 1, 0, 0, 1 }, { 1, 1, 0, 1, 1, 1 }, { 1, 0, 0, 0, 1, 0 }, { 0, 1, 1, 1, 0, 0 } };

    vector<vector<int>> table = { { 1, 0, 0, 1, 1, 0 }, { 1, 0, 1, 0, 1, 0 }, { 0, 1, 1, 0, 1, 1 }, { 0, 0, 1, 0, 0, 0 }, { 1, 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 0, 0 } };
    
    cout << solution(game_board,table);


#pragma region CloseFile 
    fin.close(); // �Է� ���� �ݱ�
    fout.close(); // ��� ���� �ݱ�
#pragma endregion
    return 0;
}