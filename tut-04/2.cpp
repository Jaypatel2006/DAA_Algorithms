#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<int> d = {2,1,2,1,3};
    vector<int> p = {100,19,27,25,15};

    vector<pair<int,int>> jobs;
    for(int i=0;i<n;i++) jobs.push_back({p[i], d[i]});

    sort(jobs.rbegin(), jobs.rend()); 

    int maxd = 0;
    for(int i=0;i<n;i++) maxd = max(maxd, jobs[i].second);

    vector<int> slot(maxd+1, -1);
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=jobs[i].second; j>0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                ans += jobs[i].first;
                break;
            }
        }
    }
    cout << ans;
}
