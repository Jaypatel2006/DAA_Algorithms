#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "(a) Dijkstra\n";
    int n1 = 5;
    vector<vector<pair<int,int>>> g(n1);
    g[0].push_back({1,10});
    g[0].push_back({2,3});
    g[1].push_back({2,1});
    g[1].push_back({3,2});
    g[2].push_back({1,4});
    g[2].push_back({3,8});
    g[2].push_back({4,2});
    g[3].push_back({4,7});
    g[4].push_back({3,9});

    int s1 = 0;
    vector<int> d1(n1, 1e9), p1(n1, -1);
    d1[s1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0, s1));

    while(!q.empty()) {
        pair<int,int> top = q.top(); q.pop();
        int dist = top.first, u = top.second;
        if(dist != d1[u]) continue;
        for(size_t i=0; i<g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if(d1[u] + w < d1[v]) {
                d1[v] = d1[u] + w;
                p1[v] = u;
                q.push(make_pair(d1[v], v));
            }
        }
    }
    for(int i=0; i<n1; i++) cout << d1[i] << " ";
    cout << "\nPath 0->3: ";
    int t1 = 3;
    vector<int> path1;
    for(int v=t1; v!=-1; v=p1[v]) path1.push_back(v);
    reverse(path1.begin(), path1.end());
    for(size_t i=0; i<path1.size(); i++) cout << path1[i] << " ";
    cout << "\n\n";

    cout << "(b) Bellman-Ford\n";
    int n2 = 4;
    vector<tuple<int,int,int>> e;
    e.push_back(make_tuple(0,1,4));
    e.push_back(make_tuple(0,2,5));
    e.push_back(make_tuple(1,2,-3));
    e.push_back(make_tuple(2,3,4));
    e.push_back(make_tuple(3,1,-6));
    int s2 = 0;
    vector<int> d2(n2, 1e9), p2(n2, -1);
    d2[s2] = 0;
    for(int i=0; i<n2-1; i++) {
        for(size_t j=0; j<e.size(); j++) {
            int u = get<0>(e[j]);
            int v = get<1>(e[j]);
            int w = get<2>(e[j]);
            if(d2[u] < 1e9 && d2[u] + w < d2[v]) {
                d2[v] = d2[u] + w;
                p2[v] = u;
            }
        }
    }
    bool neg = false;
    for(size_t j=0; j<e.size(); j++) {
        int u = get<0>(e[j]);
        int v = get<1>(e[j]);
        int w = get<2>(e[j]);
        if(d2[u] < 1e9 && d2[u] + w < d2[v]) neg = true;
    }
    if(neg) cout << "Negative cycle\n";
    else {
        for(int i=0; i<n2; i++) cout << d2[i] << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "(c) Floyd-Warshall\n";
    int n3 = 4;
    int INF = 1000000000;
    vector<vector<int>> d3(n3, vector<int>(n3, INF));
    d3[0][0]=0; d3[0][1]=5; d3[0][2]=9;
    d3[1][1]=0; d3[1][2]=2; d3[1][3]=8;
    d3[2][2]=0; d3[2][3]=7;
    d3[3][3]=0;

    for(int k=0; k<n3; k++)
        for(int i=0; i<n3; i++)
            for(int j=0; j<n3; j++)
                if(d3[i][k] < INF && d3[k][j] < INF)
                    d3[i][j] = min(d3[i][j], d3[i][k] + d3[k][j]);

    bool neg3 = false;
    for(int i=0; i<n3; i++) if(d3[i][i] < 0) neg3 = true;
    if(neg3) cout << "Negative cycle\n";
    else {
        for(int i=0; i<n3; i++) {
            for(int j=0; j<n3; j++) {
                if(d3[i][j] >= INF) cout << "INF ";
                else cout << d3[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
