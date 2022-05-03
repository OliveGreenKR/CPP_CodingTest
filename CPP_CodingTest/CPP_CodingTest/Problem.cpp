#include "pch.h"
#pragma warning(disable: 4996)

#ifdef BACK
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M_Loop(i,st,M) for(int (i)=(st);i<(M);i++)
#define M_Loop_sub(i,st,M) for(int (i)=(st);i>(M);i--)
int T;
int n, m, t, s, g, h, a, b, d, x;
int scent, crossroad1, crossroad2;
int result_1[50001], result_2[50001];
vector<int> ans;
vector<pair<int, int>> road[50001];  //[to node][dist]

void dijkstra(int start, int* result)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		result[i] = INF;

	result[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		int dist = result[node];
		q.pop();

		for (int i = 0; i < road[node].size(); i++)
		{
			int next_node = road[node][i].first;
			int next_dist = road[node][i].second;

			if (result[next_node] > dist + next_dist)
			{
				result[next_node] = dist + next_dist;
				q.push(next_node);
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();

	cin >> T;

	while (T--)
	{
		// ����,���ͽ�Ʈ�� �����,������ �Ÿ������� ��� �ʱ�ȭ
		ans.clear();
		memset(result_1, 0, sizeof(result_1));
		memset(result_2, 0, sizeof(result_2));
		for (int i = 0; i < 50001; i++)
			road[i].clear();

		cin >> n >> m >> t; // ������, ����, ������ ��
		cin >> s >> g >> h; // �����, �İ�1, �İ�2

		for (int i = 0; i < m; i++) // ������ ���� �Ÿ� �Է�
		{
			cin >> a >> b >> d;

			road[a].push_back({ b,d });
			road[b].push_back({ a,d });

			if ((a == g && b == h) || (a == h && b == g))
				scent = d; // �İ����� Ž���Ͽ� �˾Ƴ� ������ �Ÿ�
		}

		// ����������� ���ͽ�Ʈ��
		dijkstra(s, result_1);

		// �İ����� Ž���� ���ο����� ���ͽ�Ʈ�� (�� ������ ���� ���� �����Դϴ�.)
		if (result_1[g] > result_1[h]) // ����� �������� crossroad1:����� ��, crossroad2�� ����
		{
			crossroad1 = h;
			crossroad2 = g;
		}
		else
		{
			crossroad1 = g;
			crossroad2 = h;
		}
		dijkstra(crossroad2, result_2);

		for (int i = 0; i < t; i++) // ������ �ĺ� �˻�
		{
			cin >> x;
			// ����� ~ ������������ �ִܰŸ� == ����� ~ crossroad1 ~ crossroad2 ~ ������������ �ִܰŸ�
			if (result_1[x] == result_1[crossroad1] + scent + result_2[x])
				ans.push_back(x);
		}

		sort(ans.begin(), ans.end()); // ���� �������� ����

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}

}
#endif 





//int n, m, t, g, h;
//enum { MAX_IN = 2000 + 1, };
//int map[MAX_IN][MAX_IN];
//pair<int, bool> Dist[MAX_IN];
//int Dest[100];
//inline bool IsRight(int x, int y)
//{
//	if (x > n || x<1 || y > n || y < 1 || !map[x][y])
//		return false;
//	return true;
//}
//struct Node
//{
//	int dist = 0; int idx; bool ck = false;
//};
//bool operator>(const Node& A, const Node& B)
//{
//	return A.dist > B.dist;
//}
//void BFS(int st)
//{
//	priority_queue<Node, vector<Node>, greater<Node>> q;
//	Node now = { 0,st,false };
//	q.push(now);
//	Dist[now.idx].first = 0;
//	while (!q.empty())
//	{
//		//Ž�� �� ������üũ
//		//�������̸� ���°� g�� h�� ���� ���¸� ��� �ƴϸ� ���.
//		now = q.top();
//		q.pop();
//		M_Loop(i, 1, n + 1)
//		{
//			if (IsRight(now.idx, i))
//			{
//				Node next = { 0,i,now.ck }; int newdist = now.dist + map[now.idx][next.idx];
//				if ((now.idx == g && next.idx == h) || (now.idx == h && next.idx == g)) next.ck = true;
//				if (Dist[next.idx].first == -1 || Dist[next.idx].first >= newdist) //���ο� �ִܰ��
//				{
//					next.dist = newdist;
//					if (next.ck)	Dist[next.idx].second = true;
//					else if (Dist[next.idx].first != newdist) Dist[next.idx].second = false;
//					Dist[next.idx].first = newdist;
//					q.push(next);
//				}
//			}
//		}
//	}
//	return;
//}
//int main()
//{
//	FASTIO;
//	int T;
//	cin >> T;
//	M_Loop(i, 0, T)
//	{
//		::memset(Dist, -1, sizeof(Dist)); //-1�� �ʱ�ȭ
//		::memset(map, 0, sizeof(map)); //-1�� �ʱ�ȭ
//		cin >> n >> m >> t;
//		M_Loop(i, 1, n + 1) Dist[i].second = false;
//		int s;
//		cin >> s >> g >> h;
//		M_Loop(i, 0, m)
//		{
//			int a, b, d;
//			cin >> a >> b >> d;
//			map[a][b] = d;
//			map[b][a] = d;
//		}
//		M_Loop(i, 0, t)
//		{
//			cin >> Dest[i];
//		}
//
//		BFS(s);
//
//		::sort(Dest, Dest + t);
//		M_Loop(i, 0, t)
//		{
//			if (Dist[Dest[i]].first != -1 && Dist[Dest[i]].second)
//				cout << Dest[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}