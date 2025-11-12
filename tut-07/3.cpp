#include <bits/stdc++.h>
using namespace std;
int n=6;
int g[7][7]={{0},{0,0,1,1,0,0,1},
              {0,1,0,1,0,1,0},
              {0,1,1,0,1,0,0},
              {0,0,0,1,0,1,0},
              {0,0,1,0,1,0,1},
              {0,1,0,0,0,1,0}};
vector<int>path(7,0); bool found=0;
void solve(int k){
    if(k==n && g[path[k-1]][path[0]]){
        for(int i=0;i<n;i++)cout<<path[i]<<" ";
        cout<<path[0]<<"\n"; found=1; return;
    }
    for(int v=2;v<=n;v++){
        if(g[path[k-1]][v] && find(path.begin(),path.begin()+k,v)==path.begin()+k){
            path[k]=v; solve(k+1); path[k]=0;
        }
    }
}
int main(){
    path[0]=1; solve(1);
    if(!found) cout<<"none\n";
}
