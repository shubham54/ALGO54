#include<bits/stdc++.h>

using namespace std;

void compute(int dp[],int n)
{
    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    compute(dp,n);
    cout<<"Answer is= "<<dp[n]<<endl;
    return 0;
}

