#include<bits/stdc++.h>

using namespace std;

int kpal(string s,string s1)
{
    int n=s.length();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(s[i-1]==s1[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    int k;
    string s,s1;
    cin>>s>>k;
    s1=s;
    reverse(s1.begin(),s1.end());
    (kpal(s,s1)<=2*k)?cout<<"YES\n":cout<<"NO\n";
    return 0;
}
