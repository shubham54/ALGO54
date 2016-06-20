#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,ans=INT_MIN;
    cin>>n>>m;
    int A[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0 || A[i-1][j-1]==0)
                dp[i][j]=0;
            else
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<"Answer is="<<ans<<endl;
    //matrix
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
