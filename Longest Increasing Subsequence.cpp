#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=INT_MIN;
    cin>>n;
    int A[n],dp[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
