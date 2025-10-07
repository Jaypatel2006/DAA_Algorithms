#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=4;
    vector<int> p={0,1,5,8,9};
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            dp[i]=max(dp[i],p[j]+dp[i-j]);
    }
    cout<<dp[n];
}
