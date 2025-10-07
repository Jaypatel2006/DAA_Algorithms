#include <bits/stdc++.h>
using namespace std;
int main(){
    int k=2,n=10;
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    for(int i=1;i<=k;i++) dp[i][0]=0,dp[i][1]=1;
    for(int j=1;j<=n;j++) dp[1][j]=j;
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            dp[i][j]=INT_MAX;
            for(int x=1;x<=j;x++)
                dp[i][j]=min(dp[i][j],1+max(dp[i-1][x-1],dp[i][j-x]));
        }
    }
    cout<<dp[k][n];
}
