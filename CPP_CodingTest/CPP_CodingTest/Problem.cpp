#if 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
int main()
{
	int N;
	cin >> N;

	int n5 = N / 5;

	while (n5 >= 0)
	{
		int loss = N - n5 * 5;

		if (loss % 3 != 0)
		{
			n5--;
			continue;
		}
		else
		{
			cout << n5 + loss / 3 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

#endif // 1
