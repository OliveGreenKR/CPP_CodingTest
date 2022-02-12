#include "pch.h"
#ifdef BACK

#include <stdio.h>
using namespace std;
int main()
{
	int T;
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int x1, x2, y1, y2, r1, r2;
		scanf_s("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
	
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			printf("%d\n", -1);
			continue;
		}

		int D = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	
		if (D == (r1 + r2) * (r1 + r2) || D == (r1 - r2) *(r1 - r2))
			printf("%d\n", 1);
		else if (D > (r1 + r2) * (r1 + r2) || (r1 - r2) * (r1 - r2) > D)
			printf("%d\n", 0);
		else
			printf("%d\n", 2);
	}
}
#endif