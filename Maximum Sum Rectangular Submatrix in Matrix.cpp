#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,sum,ans=INT_MIN,temp;
    cin>>n>>m;
    int A[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    int dp[n],k=0;
    for(int i=0;i<m;i++)
    {
        memset(dp,0,sizeof(dp));
        for(int j=i;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                dp[k]+=A[k][j];
            }
            temp=sum=dp[0];
            for(int k=1;k<n;k++)
            {
                temp=max(dp[k],dp[k]+temp);
                sum=max(sum,temp);
            }
            ans=max(ans,sum);
        }
    }
    cout<<"Answer is="<<ans<<endl;
    return 0;
}
