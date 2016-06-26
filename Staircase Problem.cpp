#include<bits/stdc++.h>

using namespace std;

void compute(int dp[],int n)//you are allowed to take either one step or two step
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
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
    cout<<"Steps needed is= "<<dp[n]<<endl;
    return 0;
}
