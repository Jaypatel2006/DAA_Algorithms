#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int costMat[N][N] = {
    {0,10,15,20,10},
    {10,0,35,25,17},
    {15,35,0,30,28},
    {20,25,30,0,22},
    {10,17,28,22,0}
};

int bestCost = INT_MAX, nodesExpanded = 0;
vector<int> bestTour, currTour(N, 0);

int reduceMatrix(vector<vector<int>>& m) {
    int cost = 0, n = m.size();
    // Row reduction
    for (int i = 0; i < n; i++) {
        int rowMin = *min_element(m[i].begin(), m[i].end());
        if (rowMin != INT_MAX && rowMin > 0)
            for (int j = 0; j < n; j++) if (m[i][j] < INT_MAX) m[i][j] -= rowMin;
        cost += (rowMin == INT_MAX ? 0 : rowMin);
    }
    // Column reduction
    for (int j = 0; j < n; j++) {
        int colMin = INT_MAX;
        for (int i = 0; i < n; i++) colMin = min(colMin, m[i][j]);
        if (colMin != INT_MAX && colMin > 0)
            for (int i = 0; i < n; i++) if (m[i][j] < INT_MAX) m[i][j] -= colMin;
        cost += (colMin == INT_MAX ? 0 : colMin);
    }
    return cost;
}

void tsp(int level, int cost, vector<vector<int>> m) {
    nodesExpanded++;
    if (cost >= bestCost) return;

    if (level == N) {
        int last = currTour[level - 1];
        if (m[last][0] < INT_MAX && cost + m[last][0] < bestCost) {
            bestCost = cost + m[last][0];
            bestTour = currTour;
        }
        return;
    }

    int u = currTour[level - 1];
    for (int v = 0; v < N; v++) {
        if (find(currTour.begin(), currTour.begin() + level, v) != currTour.begin() + level)
            continue;
        if (m[u][v] == INT_MAX) continue;

        auto temp = m;
        for (int i = 0; i < N; i++) {
            temp[u][i] = INT_MAX;
            temp[i][v] = INT_MAX;
        }
        temp[v][0] = INT_MAX;

        int add = m[u][v];
        int redCost = reduceMatrix(temp);

        currTour[level] = v;
        tsp(level + 1, cost + add + redCost, temp);
    }
}

int main() {
    vector<vector<int>> m(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (costMat[i][j]) m[i][j] = costMat[i][j];

    int baseCost = reduceMatrix(m);
    currTour[0] = 0;
    tsp(1, baseCost, m);

    cout << "Optimal Tour: ";
    for (int city : bestTour) cout << char('A' + city) << " ";
    cout << "A\nTotal Cost = " << bestCost << "\nNodes Expanded = " << nodesExpanded << "\n";
}
