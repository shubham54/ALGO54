#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,s1;
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
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"Amswer="<<dp[l][m]<<endl;
    //matrix print
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //common subsequence
    string s2="";
    while(dp[l][m]!=0)
    {
        if(dp[l][m]==dp[l-1][m])
            l--;
        else if(dp[l][m]==dp[l][m-1])
            m--;
        else
        {
            s2+=s1[m-1];
            l--;m--;
        }
    }
    reverse(s2.begin(),s2.end());
    cout<<s2<<endl;
    return 0;
}
