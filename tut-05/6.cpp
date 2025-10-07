#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<double> p={0.2,0.5,0.3};
    int n=p.size();
    vector<vector<double>> cost(n,vector<double>(n,0)),sum(n,vector<double>(n,0));
    for(int i=0;i<n;i++) cost[i][i]=sum[i][i]=p[i];
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            sum[i][j]=sum[i][j-1]+p[j];
            cost[i][j]=INT_MAX;
            for(int r=i;r<=j;r++){
                double left=(r>i)?cost[i][r-1]:0;
                double right=(r<j)?cost[r+1][j]:0;
                cost[i][j]=min(cost[i][j],left+right+sum[i][j]);
            }
        }
    }
    cout<<cost[0][n-1];
}
