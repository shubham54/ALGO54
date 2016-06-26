#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;stack<int>S;//stack to print path
    cin>>n;
    int C[n],dp[n],P[n];//C contain range
    for(int i=0;i<n;i++){
        cin>>C[i];
    }
    dp[0]=P[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(C[j]+j>=i){
                if(dp[i]>dp[j]+1){
                    dp[i]=dp[j]+1;
                    P[i]=j;
                }
            }
        }
    }
    cout<<"Answer is="<<dp[n-1]<<endl;
    cout<<"Path is"<<endl;
    n--;S.push(n);
    while(P[n]!=0){
        S.push(P[n]);
        n=P[n];
    }
    cout<<"0 ";
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}
