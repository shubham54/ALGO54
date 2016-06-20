#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,s,e,c,ans=INT_MIN;//s=start,e=end,c=profit
    cin>>n;
    pair<int,pair<int,int> >P[n];
    int dp[n];
    for(int i=0;i<n;i++)
    {
        cin>>s>>e>>c;
        P[i]=make_pair(e,make_pair(s,c));
        dp[i]=c;
    }
    sort(P,P+n);
    for(int i=0;i<n;i++)
        dp[i]=P[i].second.second;
    for(int i=1;i<n;i++)
    {
        c=P[i].second.second;
        for(int j=0;j<i;j++)
        {
            if(P[j].first<=P[i].second.first)//comparing end time of both job
                dp[i]=max(dp[i],dp[j]+c);
        }
    }
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<"Answer is="<<ans<<endl;
    //matrix
    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}
