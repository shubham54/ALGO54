//(0/1) Knapsack with DP and path followed
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int weight,n,w,v;
    cin>>n>>weight;
    pair<int,int>P[n];
    for(int i=0;i<n;i++)
    {
        cin>>w>>v;
        P[i]=make_pair(w,v);
    }
    sort(P,P+n);
    int dp[n][weight+1];
    w=P[0].first;v=P[0].second;
    for(int j=0;j<=weight;j++)//for first row
    {
        if(j<w)
            dp[0][j]=0;
        else
            dp[0][j]=v;
    }
    for(int i=1;i<n;i++)
    {
        w=P[i].first;v=P[i].second;
        for(int j=0;j<=weight;j++)
        {
            if(j==0)
                dp[i][j]=0;
            else
            {
                if(j<w)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],v+dp[i-1][j-w]);
            }
        }
    }
    //matrix print
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=weight;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Answer is="<<dp[n-1][weight]<<endl;
    //to print path
    int i=n-1,j=weight;
    stack<int>mystack;
    while(dp[i][j]!=0)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else
        {
            if(i==0)
            {
                mystack.push(i);
                break;
            }
            mystack.push(i);
            j-=P[i].first;
            i--;
        }
    }
    cout<<"Path Followed"<<endl;
    while(!mystack.empty())
    {
        int top=mystack.top();
        mystack.pop();
        cout<<P[top].first<<" "<<P[top].second<<endl;//first weight second value
    }
    return 0;
}
