#include<bits/stdc++.h>

using namespace std;

void LIS(int A[],int n)
{
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        A[i]=dp[i];
    }
}

int main()
{
    int n,ma=INT_MIN;
    cin>>n;
    int A[n],B[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
        B[n-i-1]=A[i];
    }
    LIS(A,n);LIS(B,n);
    for(int i=0;i<n;i++){
        ma=max(ma,A[i]+B[n-i-1]-1);
    }
    cout<<"Answer is= "<<ma<<endl;
    return 0;
}
