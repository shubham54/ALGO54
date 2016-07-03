#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length(),ans=1,index=0;
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            ans=2;index=i;
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            int k=i+j-1;
            if(dp[j+1][k-1] && s[j]==s[k]){
                dp[j][k]=1;
                ans=i;
                index=j;
            }
        }
    }
    cout<<"Longest palindrome substring is= ";
    for(int i=index;i<index+ans;i++){
        cout<<s[i];
    }
    cout<<endl;
    cout<<"Length is= "<<ans<<endl;
    return 0;
}
