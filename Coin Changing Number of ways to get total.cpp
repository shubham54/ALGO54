#include<bits/stdc++.h>

using namespace std;

int main()
{
    int sum,n;
    cin>>n>>sum;
    int W[n];
    for(int i=0;i<n;i++)
        cin>>W[i];
    sort(W,W+n);
    int dp[n][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++)
    {
        if(i%W[0])
            dp[0][i]=0;
        else
            dp[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(W[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-W[i]];
        }
    }
    cout<<"Answer is="<<dp[n-1][sum]<<endl;
    //matrix
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
