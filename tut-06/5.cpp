#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>&c,vector<vector<int>>&f,int s,int t,vector<int>&p){
    fill(p.begin(),p.end(),-1); p[s]=s; queue<int>q; q.push(s);
    while(!q.empty()){int u=q.front();q.pop();
        for(int v=0;v<c.size();v++) if(p[v]==-1&&c[u][v]-f[u][v]>0){p[v]=u;q.push(v);}
    } return p[t]!=-1;
}
int maxflow(vector<vector<int>> c,int s,int t){
    int n=c.size(),flow=0; vector<vector<int>>f(n,vector<int>(n,0)),paths;
    vector<int>p(n);
    while(bfs(c,f,s,t,p)){
        int aug=1e9;
        for(int v=t;v!=s;v=p[v]) aug=min(aug,c[p[v]][v]-f[p[v]][v]);
        for(int v=t;v!=s;v=p[v]){f[p[v]][v]+=aug;f[v][p[v]]-=aug;}
        flow+=aug;
    } return flow;
}
int main(){
    cout<<"(a) Max Flow Example\n";
    vector<vector<int>> c1={{0,16,13,0,0,0},{0,0,10,12,0,0},{0,4,0,0,14,0},{0,0,9,0,0,20},{0,0,0,7,0,4},{0,0,0,0,0,0}};
    cout<<"Max Flow="<<maxflow(c1,0,5)<<"\n\n";

    cout<<"(b) Bipartite Matching Example\n";
    vector<vector<int>> c2(8,vector<int>(8,0));
    for(int i=1;i<=3;i++) c2[0][i]=1;
    c2[1][4]=c2[1][5]=1; c2[2][5]=c2[2][6]=1; c2[3][6]=c2[3][7]=1;
    for(int i=4;i<=7;i++) c2[i][8-1]=1;
    cout<<"Max Matching="<<maxflow(c2,0,7)<<"\n\n";

    cout<<"(c) Min-Cost Max-Flow Example\n";
    int n=6; int s=0,t=5; int flow=0,cost=0;
    vector<vector<int>> cap(n,vector<int>(n,0)),costs(n,vector<int>(n,0));
    auto add=[&](int u,int v,int c,int w){cap[u][v]=c;costs[u][v]=w;costs[v][u]=-w;};
    add(0,1,10,2); add(0,2,2,4); add(1,2,6,6); add(1,3,6,2);
    add(2,4,5,2); add(3,4,8,1); add(3,5,5,3); add(4,5,10,2);
    vector<vector<int>> f(n,vector<int>(n,0));
    while(true){
        vector<int>d(n,1e9),p(n,-1); vector<bool>in(n,0); d[s]=0; queue<int>q; q.push(s);
        while(!q.empty()){int u=q.front();q.pop();in[u]=0;
            for(int v=0;v<n;v++) if(cap[u][v]-f[u][v]>0 && d[u]+costs[u][v]<d[v]){
                d[v]=d[u]+costs[u][v]; p[v]=u; if(!in[v]) in[v]=1,q.push(v);
            }
        }
        if(p[t]==-1) break;
        int aug=1e9; for(int v=t;v!=s;v=p[v]) aug=min(aug,cap[p[v]][v]-f[p[v]][v]);
        for(int v=t;v!=s;v=p[v]){f[p[v]][v]+=aug;f[v][p[v]]-=aug;cost+=aug*costs[p[v]][v];}
        flow+=aug;
    }
    cout<<"Flow="<<flow<<" Cost="<<cost<<"\n";
}
