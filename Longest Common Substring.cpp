#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,s1;
    int large=INT_MIN,index;
    cin>>s>>s1;
    int l=s.length(),m=s1.length();
    int dp[l+1][m+1];
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s[i-1]==s1[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=0;
        }
    }
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(large<dp[i][j])
            {
                large=dp[i][j];
                index=j;
            }
        }
    }
    cout<<"Answer is="<<large<<endl;
    //matrix
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(large!=0)
        cout<<"substring is="<<s1.substr(abs(index-large),large)<<endl;
    return 0;
}
