#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> placeCellTowers(vector<int>& houses) {
    sort(houses.begin(), houses.end());
    int n = houses.size();
    int i = 0;
    vector<int> towers;

    while (i < n) {
        int loc = houses[i] + 4;
        while (i < n && houses[i] <= loc)
            i++;

        int towerPos = houses[i - 1];
        towers.push_back(towerPos);

        while (i < n && houses[i] <= towerPos + 4)
            i++;
        
    }

    return towers;
}

int main() {
    vector<int> houses = {1, 2, 6, 9, 11};
    vector<int> towers = placeCellTowers(houses);

    for (int pos : towers)
        cout << pos << " ";
    cout << endl;

    return 0;
}
