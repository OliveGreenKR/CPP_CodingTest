#include <iostream>
#include <vector>

void minimumBribes(std::vector<int> q) {
    int bribes = 0;
    int n = q.size();

    for (int i = n - 1; i >= 0; i--)
    {
        const int now = q[i];
        const int expected = i + 1;

        if (now - expected > 2)
        {
            std::cout << "Too chaotic" << std::endl;
            return;
        }

        for (int bridable = std::max(0, now - 2); bridable < i; bridable++)
        {
            if (q[bridable] > now)
            {
                bribes++;
            }
        }
    }

    std::cout << bribes << std::endl;
}

int main()
{

}