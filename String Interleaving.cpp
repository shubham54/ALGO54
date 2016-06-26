#include<bits/stdc++.h>

using namespace std;

int cal(string s,string s1,string s3)
{
    int n=s.length();
    int m=s1.length();

    int dp[n+1][m+1];
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        if(s1[i-1]==s3[i-1])
            dp[0][i]=dp[0][i-1];
        else
            dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        if(s[i-1]==s3[i-1])
            dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s3[i+j-1]==s[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else if(s3[i+j-1]==s1[j-1]){
                dp[i][j]=dp[i][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}

int main()
{
    string s,s1,s3;
    cin>>s>>s1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s3;
        (cal(s,s1,s3)==1)?cout<<"True\n":cout<<"False\n";
    }
    return 0;
}
