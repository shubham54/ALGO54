#include<bits/stdc++.h>

using namespace std;

int main()
{
    int sum,n;
    cin>>n>>sum;
    int W[n];
    for(int i=0;i<n;i++)
        cin>>W[i];
    int dp[n][sum+1];
    sort(W,W+n);
    for(int i=0;i<=sum;i++)
    {
        if(W[0]==i || i==0)
            dp[0][i]=1;
        else
            dp[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(W[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-W[i]];
        }
    }
    if(dp[n-1][sum])
        cout<<"Possible"<<endl;
    else
        cout<<"Not Possible"<<endl;
    //matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //Path
    n-=1;
    stack<int>mystack;
    while(n!=0 && sum!=0)
    {
        if(dp[n][sum]==dp[n-1][sum])
            n--;
        else
        {
            mystack.push(W[n]);
            sum-=W[n];
            n--;
        }
    }
    if(!mystack.empty())
        cout<<"Weight Taken=";
    while(!mystack.empty())
    {
        cout<<mystack.top()<<" ";
        mystack.pop();
    }
    return 0;
}
