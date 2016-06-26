#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,q,a,b,a1,b1,ans;
    cin>>n>>m;
    int A[n][m],dp[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+A[i-1][j-1]-dp[i-1][j-1];
            }
        }
    }
    cin>>q;//no. of query
    while(q--){
        cin>>a>>b>>a1>>b1;//a is first row,b is first col,a1 is second row,b1 is second col
        a++;b++;a1++;b1++;
        ans=dp[a1][b1]-dp[a-1][b1]-dp[a1][b-1]+dp[a-1][b-1];
        cout<<"Answer is= "<<ans<<endl;
    }
    return 0;
}
