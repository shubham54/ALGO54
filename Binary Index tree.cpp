#include<bits/stdc++.h>

using namespace std;

int B[100001],A[100001];

void update(int i,int val,int n)
{
    for(;i<=n;i+=i&(-i)){
        B[i]+=val;
    }
}

int query(int i)
{
    int sum=0;
    for(;i>0;i-=i&(-i)){
        sum+=B[i];
    }
    return sum;
}

int main()//1 based index query and update
{
    int n,a,b,q,choice,diff;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        update(i,A[i],n);
    }
    cin>>q;
    while(q--){
        cin>>choice;
        if(choice==1){
            cin>>a>>b;//range from a to b
            cout<<query(b)-query(a-1)<<endl;
        }
        else{
            cin>>a>>b;//it means A[a]=b
            diff=b-A[a];A[a]=b;
            update(a,diff,n);
        }
    }
    return 0;
}
