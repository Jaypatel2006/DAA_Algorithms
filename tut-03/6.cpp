
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSkyline(vector<vector<int>>& left, vector<vector<int>>& right) {
    vector<vector<int>> res;
    int h1 = 0, h2 = 0, i = 0, j = 0;
    while(i < (int)left.size() && j < (int)right.size()) {
        int x = 0;
        if(left[i][0] < right[j][0]) {
            x = left[i][0];
            h1 = left[i][1];
            i++;
        } else if(right[j][0] < left[i][0]) {
            x = right[j][0];
            h2 = right[j][1];
            j++;
        } else {
            x = left[i][0];
            h1 = left[i][1];
            h2 = right[j][1];
            i++;
            j++;
        }
        int height = max(h1, h2);
        if(res.empty() || res.back()[1] != height) res.push_back({x, height});
    }
    while(i < (int)left.size()) {
        res.push_back(left[i]);
        i++;
    }
    while(j < (int)right.size()) {
        res.push_back(right[j]);
        j++;
    }
    return res;
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings, int l, int r) {
    if(l == r) {
        int Li = buildings[l][0];
        int Ri = buildings[l][1];
        int Hi = buildings[l][2];
        return {{Li, Hi}, {Ri, 0}};
    }
    int mid = (l + r) / 2;
    auto left = getSkyline(buildings, l, mid);
    auto right = getSkyline(buildings, mid + 1, r);
    return mergeSkyline(left, right);
}

int main() {
    vector<vector<int>> A = {{1, 5, 11}, {2, 7, 6}, {3, 9, 13}, {12, 16, 7}, {14, 25, 3}, {19, 22, 18}, {23, 29, 13}, {24, 28, 4}};
    auto ans = getSkyline(A, 0, (int)A.size() - 1);
    for(auto &pt : ans) cout << "[" << pt[0] << ", " << pt[1] << "] ";
    cout << endl;
}
