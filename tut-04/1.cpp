#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3, W = 50;
    vector<int> v = {60, 100, 120};
    vector<int> w = {10, 20, 30};
    vector<pair<double,int>> ratio;

    for(int i=0;i<n;i++) ratio.push_back({(double)v[i]/w[i],i});
    sort(ratio.rbegin(), ratio.rend());

    double ans = 0;
    for(auto x: ratio){
        int idx = x.second;
        if(w[idx] <= W){
            ans += v[idx];
            W -= w[idx];
        } else {
            ans += v[idx] * ((double)W / w[idx]);
            break;
        }
    }
    cout << ans;
}
