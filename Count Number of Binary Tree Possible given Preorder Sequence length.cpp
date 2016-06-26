#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    dp[0]=1;dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=2*dp[i-1];
        for(int j=2;j<i;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    cout<<"Answer is= "<<dp[n]<<endl;
    return 0;
}
