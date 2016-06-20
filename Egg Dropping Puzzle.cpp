#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;//n denotes eggs and k denotes floor
    cin>>n>>k;
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++)
        dp[1][i]=i;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            if(i>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                for(int r=1;r<=j;r++)
                    dp[i][j]=min(dp[i][j],1+max(dp[i-1][r-1],dp[i][j-r]));
            }
        }
    }
    cout<<"Answer is ="<<dp[n][k]<<endl;
    //matrix
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
