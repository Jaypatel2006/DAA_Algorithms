#include <bits/stdc++.h>
using namespace std;
int n=4,sol=0,nodes=0,pruned=0;


bool safe(vector<int>&a,int r,int c){
    for(int i=0;i<r;i++)
        if(a[i]==c||abs(a[i]-c)==abs(i-r)) return false;
    return true;
}
void solve(vector<int>&a,int r){
    if(r==n){sol++;for(int x:a)cout<<x+1<<" ";cout<<"\n";return;}
    for(int c=0;c<n;c++){
        nodes++;
        if(safe(a,r,c)){a[r]=c;solve(a,r+1);}
        else pruned++;
    }
}
int main(){
    vector<int>a(n);
    solve(a,0);
    cout<<"Total solutions="<<sol<<"\nNodes="<<nodes<<" Pruned="<<pruned<<"\n";
} 
