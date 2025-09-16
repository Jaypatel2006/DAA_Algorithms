#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minRefuelingStops(int tank, int distance, vector<int>& pumps) {
    pumps.push_back(distance);
    int stops = 0;
    int current_pos = 0;
    int i = 0;
    int n = pumps.size();
    
    while (current_pos + tank < distance) {
        int last_pos = current_pos;
        while (i < n && pumps[i] <= current_pos + tank) {
            i++;
        }
        if (last_pos == pumps[i - 1]) {
            return -1;
        }
        current_pos = pumps[i - 1];
        stops++;
    }
    
    return stops;
}

int main() {
    int tank = 10;
    int distance = 25;
    vector<int> pumps = {4, 7, 12, 18, 22};

    int minStops = minRefuelingStops(tank, distance, pumps);
    cout << minStops << endl;

    return 0;
}
