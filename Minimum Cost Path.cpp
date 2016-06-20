#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,ans=INT_MIN;
    cin>>n>>m;
    int A[n][m],dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    dp[0][0]=A[0][0];
    for(int i=1;i<m;i++)
        dp[0][i]=dp[0][i-1]+A[0][i];
    for(int i=1;i<n;i++)
        dp[i][0]=dp[i-1][0]+A[i][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"Answer is="<<dp[n-1][m-1]<<endl;
    //matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
