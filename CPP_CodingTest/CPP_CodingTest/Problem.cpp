#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string gridChallenge(vector<string> grid) 
{
	const int size = grid.size();

	for (string& row : grid)
	{
		std::sort(row.begin(), row.end());
	}

	for (int j = 0; j < size; ++j)
	{
		for (int i = 1; i < size; ++i)
		{
			if (grid[i][j] < grid[i - 1][j])
			{
				return "NO";
			}
		}
	}

	return "YES";
}


int main()
{

}