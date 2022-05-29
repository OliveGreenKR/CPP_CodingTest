#pragma warning(disable: 4996)
#define mz
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>

using namespace std;
struct Pos
{
    int y; int x;
};
Pos operator+(const Pos&A, const Pos&B)
{
    return { A.y+B.y,A.x+B.x };
}
bool operator==(const Pos& A, const Pos& B)
{
    return A.y==B.y&&A.x==B.x ;
}

inline bool IsRight(vector<string>& maze, Pos now, string path)
{
    int col = maze[0].length();
    int row = maze.size();
    int len = path.length();
    if (now.y<=row&&now.x<=col&&now.y>0&&now.x>0)
    {
       auto it = ::find(path.begin(), path.end(), maze[now.y-1][now.x-1]);
       if (it!=path.end())
           return true;
    }
    return false;
}

inline vector<string> getQuery(string& query)
{
    vector<string> ret;
    auto left = query.begin();
    auto right = query.begin();
    while (ret.size()<5)
    {
        string tmp;
        if (ret.size()<4)
        {
            right = ::find(left, query.end(), ' ');
            tmp = query.substr(left-query.begin(), right-left);
        }
        else
        {
            tmp = query.substr(left-query.begin(),query.end()-left);
        }
        ret.push_back(tmp);
        left = right+1;
    }
    return ret;
}

int BFS(vector<string>& maze, string& quary)
{
    Pos dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };
  
    //query «ÿ√º
    auto ans = getQuery(quary);
    Pos now  = { ::stoi(ans[0]),::stoi(ans[1]) };
    Pos end = { ::stoi(ans[2]),::stoi(ans[3]) };
    string path = ans[4];

    int col = maze[0].length();
    int row = maze.size();
    vector<vector<bool>> visited (row+1,vector<bool>(col+1,false));
   
    struct Node :Pos
    {
        int cnt = 0;
    };
    queue<Node> q;
    visited[now.y][now.x] = true;
    q.push({ now,1 });
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        for (Pos go : dir)
        {
            Pos next = now+go;
            if (IsRight(maze, next, path) && !visited[next.y][next.x])
            {
                visited[next.y][next.x] = true;
                q.push({ next,now.cnt+1 });
                if (next==end) return now.cnt+1;
            }
        }
    }
    return -1;
}

vector<int> solution(vector<string> maze, vector<string> queries) {
    vector<int> answer;
    for (string qy : queries)
    {
        answer.push_back(BFS(maze, qy));
    }
    return answer;
}


#ifdef mz1
int main()
{
    vector<string> maze = { "AAA", "ABB", "ABA" };
    vector<string> queries = { "1 1 1 3 A", "1 3 3 1 A", "1 1 3 3 A", "1 1 3 3 AB" };

    for (int c : solution(maze, queries))
    {
        cout<<c<<" ";
    }

    return 0;
}
#endif // Chg
