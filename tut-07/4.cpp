#include <bits/stdc++.h>
using namespace std;
vector<int>a={3,4,5,6,7},cur; int n=5,T=12;
void solve(int i,int sum){
    if(sum==T){for(int x:cur)cout<<x<<" ";cout<<"\n";return;}
    if(i==n||sum>T) return;
    int rem=0; for(int j=i;j<n;j++) rem+=a[j];
    if(sum+rem<T) return;
    cur.push_back(a[i]); solve(i+1,sum+a[i]);
    cur.pop_back(); solve(i+1,sum);
}
int main(){solve(0,0);}
