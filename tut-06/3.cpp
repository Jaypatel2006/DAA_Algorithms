#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int v, vector<int> &parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) parent[u] = v;
    else if (rank[v] < rank[u]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST() {
    int n = 4;
    vector<Edge> edges = {
        {0,1,1}, {1,2,2}, {0,2,3}, {2,3,4}, {1,3,5}
    };
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n), rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;
    vector<Edge> mst;
    int total = 0;
    for(auto e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);
        if(pu != pv) {
            mst.push_back(e);
            total += e.w;
            unionSet(pu, pv, parent, rank);
        }
    }
    cout << "Kruskal MST:\n";
    for(auto e : mst)
        cout << e.u << " - " << e.v << " (" << e.w << ")\n";
    cout << "Total Weight = " << total << "\n";
}

void primMST() {
    int n = 4;
    int graph[4][4] = {
        {0,1,3,0},
        {1,0,2,5},
        {3,2,0,4},
        {0,5,4,0}
    };
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);
    key[0] = 0;
    for(int i=0;i<n-1;i++){
        int u=-1;
        for(int j=0;j<n;j++)
            if(!inMST[j] && (u==-1 || key[j]<key[u]))
                u=j;
        inMST[u]=true;
        for(int v=0;v<n;v++){
            if(graph[u][v]!=0 && !inMST[v] && graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    int total=0;
    cout << "Prim MST:\n";
    for(int i=1;i<n;i++){
        cout << parent[i] << " - " << i << " (" << graph[i][parent[i]] << ")\n";
        total += graph[i][parent[i]];
    }
    cout << "Total Weight = " << total << "\n";
}

int main() {
    kruskalMST();
    primMST();
    cout << "Both give same total weight (7)\n";
    return 0;
}
