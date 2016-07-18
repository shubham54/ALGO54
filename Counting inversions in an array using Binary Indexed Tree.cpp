#include<bits/stdc++.h>

using namespace std;

int read(int x,int C[])
{
    int sum=0;
    for(;x>0;x-=x&(-x)){
        sum+=C[x];
    }
    return sum;
}

void update(int x,int n,int C[],int val)
{
    for(;x<=n;x+=x&(-x)){
        C[x]+=val;
    }
}

int main()
{
    int n,con=0;
    cin>>n;
    int A[n],B[n],C[n+1];
    for(int i=0;i<n;i++){
        cin>>A[i];
        B[i]=A[i];
    }
    sort(B,B+n);
    C[0]=0;
    for(int i=0;i<n;i++){
        int ind=lower_bound(B,B+n,A[i])-B;
        A[i]=ind+1;
        C[i+1]=0;
    }
    for(int i=n-1;i>=0;i--){
        con+=read(A[i]-1,C);
        update(A[i],n,C,1);
    }
    cout<<con<<endl;
    return 0;
}
