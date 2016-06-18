#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,sum;
    cin>>n>>sum;
    int W[n];
    for(int i=0;i<n;i++)
        cin>>W[i];
    sort(W,W+n);
    int dp[n][sum+1];
    for(int i=0;i<=sum;i++)
    {
        if(W[0]>i)
            dp[0][i]=0;
        else
            dp[0][i]=1+dp[0][i-W[0]];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(W[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i][j-W[i]]+1,dp[i-1][j]);
        }
    }
    cout<<"No. Of Coin Required="<<dp[n-1][sum]<<endl;
    //Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
