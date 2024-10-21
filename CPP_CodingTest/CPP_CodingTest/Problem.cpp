#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int truckTour(vector<pair<int, int>> pumps) {
    int total_tank = 0;  // Total petrol balance across the full circle
    int current_tank = 0;  // Current petrol balance for the current tour
    int start_index = 0;  // Starting index of the valid petrol pump

    for (int i = 0; i < pumps.size(); i++)
    {
        int petrol = pumps[i].first;  // Petrol provided by the current pump
        int distance = pumps[i].second;  // Distance to the next pump

        total_tank += petrol - distance;
        current_tank += petrol - distance;

        if (current_tank < 0)
        {
            start_index = i + 1;
            current_tank = 0;
        }
    }

    return (total_tank >= 0) ? start_index : -1;
}


int main()
{

}