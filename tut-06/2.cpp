#include <bits/stdc++.h>
using namespace std;

void topoDFS(int u, vector<int> adj[], vector<int>& vis, stack<int>& st){
    vis[u]=1;
    for(int v:adj[u])
        if(!vis[v]) topoDFS(v,adj,vis,st);
    st.push(u);
}

void topoSort(int n, vector<int> adj[]){
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++)
        if(!vis[i]) topoDFS(i,adj,vis,st);
    cout<<"Topological Order: ";
    while(!st.empty()){
        cout<<st.top()<<" ";       
        st.pop();
    }
    cout<<endl;
}

void dfsRev(int u, vector<int> rev[], vector<int>& vis, vector<int>& comp){
    vis[u]=1;
    comp.push_back(u);
    for(int v:rev[u])
        if(!vis[v]) dfsRev(v,rev,vis,comp);
}

void scc(int n, vector<int> adj[]){
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++)
        if(!vis[i]) topoDFS(i,adj,vis,st);
    vector<int> rev[n];
    for(int i=0;i<n;i++)
        for(int v:adj[i])
            rev[v].push_back(i);
    fill(vis.begin(),vis.end(),0);
    cout<<"SCCs:\n";
    while(!st.empty()){
        int u=st.top(); st.pop();
        if(!vis[u]){
            vector<int> comp;
            dfsRev(u,rev,vis,comp);
            for(int x:comp) cout<<x<<" ";
            cout<<endl;
        }
    }
}

int main(){
    int n=6;
    vector<int> dag[6]={{1,2},{3},{3,4},{5},{5},{}};
    topoSort(n,dag);

    vector<int> dir[8]={{1},{2,3},{0},{4},{5,7},{6,4},{5},{4}};
    scc(8,dir);
}
