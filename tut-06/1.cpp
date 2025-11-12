#include <bits/stdc++.h>
using namespace std;

int timer=0;
vector<int> disc, fin;
vector<vector<int>> adj;
vector<string> edgesType;

void bfs(int n, vector<int> adj[], int start){
    vector<int> vis(n,0);
    queue<int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
    }
    cout<<endl;
}

void dfsTrav(int u, vector<int> adj[], vector<int>& vis){
    vis[u]=1;
    cout<<u<<" ";
    for(int v:adj[u])
        if(!vis[v]) dfsTrav(v,adj,vis);
}

void dfs(int n, vector<int> adj[], int start){
    vector<int> vis(n,0);
    dfsTrav(start,adj,vis);
    cout<<endl;
}

void dfsClass(int u, vector<int>& vis){
    vis[u]=1;
    disc[u]=++timer;
    for(int v:adj[u]){
        if(!vis[v]){
            edgesType.push_back(to_string(u)+"-"+to_string(v)+": tree");
            dfsClass(v,vis);
        }
        else if(!fin[v])
            edgesType.push_back(to_string(u)+"-"+to_string(v)+": back");
        else if(disc[u]<disc[v])
            edgesType.push_back(to_string(u)+"-"+to_string(v)+": forward");
        else
            edgesType.push_back(to_string(u)+"-"+to_string(v)+": cross");
    }
    fin[u]=++timer;
}

bool dfsDir(int u, vector<int> adj[], vector<int>& vis, vector<int>& rec){
    vis[u]=rec[u]=1;
    for(int v:adj[u]){
        if(!vis[v] && dfsDir(v,adj,vis,rec)) return true;
        else if(rec[v]) return true;
    }
    rec[u]=0;
    return false;
}

bool hasCycleDirected(int n, vector<int> adj[]){
    vector<int> vis(n,0), rec(n,0);
    for(int i=0;i<n;i++)
        if(!vis[i] && dfsDir(i,adj,vis,rec)) return true;
    return false;
}

bool dfsUndir(int u,int p, vector<int> adj[], vector<int>& vis){
    vis[u]=1;
    for(int v:adj[u]){
        if(!vis[v]){
            if(dfsUndir(v,u,adj,vis)) return true;
        }else if(v!=p) return true;
    }
    return false;
}

bool hasCycleUndirected(int n, vector<int> adj[]){
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
        if(!vis[i] && dfsUndir(i,-1,adj,vis)) return true;
    return false;
}

int main(){
    int n=6;
    vector<int> adj1[6]={{1,2},{0,3,4},{0,4},{1,5},{1,2,5},{3,4}};
    cout<<"BFS: "; bfs(n,adj1,0);
    cout<<"DFS: "; dfs(n,adj1,0);

    adj={{1,2},{0,3,4},{0,4},{1,5},{1,2,5},{3,4}};
    disc.assign(n,0);
    fin.assign(n,0);
    vector<int> vis(n,0);
    timer=0;
    dfsClass(0,vis);
    cout<<"\nTimes:\n";
    for(int i=0;i<n;i++) cout<<"V"<<i<<" d="<<disc[i]<<" f="<<fin[i]<<endl;
    cout<<"\nEdges:\n";
    for(auto &e:edgesType) cout<<e<<endl;

    int n1=4;
    vector<int> dir[4]={{1},{2},{3},{1}};
    cout<<"\nDirected Graph: "<<(hasCycleDirected(n1,dir)?"Cycle":"No Cycle")<<endl;
    vector<int> undir[4]={{1,2},{0,2},{0,1,3},{2}};
    cout<<"Undirected Graph: "<<(hasCycleUndirected(n1,undir)?"Cycle":"No Cycle")<<endl;
}
