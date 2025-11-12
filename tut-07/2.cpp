#include <bits/stdc++.h>
using namespace std;
int n,best=1e9; vector<int>a={3,4,5,7,9},x,y,ans1,ans2;
void dfs(int i,int s1,int s2){
    if(i==n){
        if(abs(s1-s2)<best){best=abs(s1-s2);ans1=x;ans2=y;}
        return;
    }
    x.push_back(a[i]); dfs(i+1,s1+a[i],s2); x.pop_back();
    y.push_back(a[i]); dfs(i+1,s1,s2+a[i]); y.pop_back();
}
int main(){
    n=a.size();
    dfs(0,0,0);
    cout<<"Set1:";for(int v:ans1)cout<<v<<" ";
    cout<<"\nSet2:";for(int v:ans2)cout<<v<<" ";
    cout<<"\nMin diff="<<best<<"\n";
}
