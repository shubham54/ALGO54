#include<bits/stdc++.h>

using namespace std;

int A[100000],seg[150000];


int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l){
        return 0;
    }
    if(l <= start and end <= r){
        return seg[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node+1, start, mid, l, r);
    int p2 = query(2*node+2, mid+1, end, l, r);
    return (p1 + p2);
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] = val;
        seg[node] = val;
    }
    else
    {
        int mid = start + (end-start) / 2;
        if(start <= idx and idx <= mid){
            update(2*node+1, start, mid, idx, val);
        }
        else{
            update(2*node+2, mid+1, end, idx, val);
        }
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
}

void build(int node, int start, int end)
{
    if(start == end){
        seg[node] = A[start];
    }
    else{
        int mid = start + (end-start) / 2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
}



int main()
{
    int n,q,choice,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    build(0,0,n-1);
    cin>>q;
    while(q--){
        cin>>choice;
        if(choice==1){
            cin>>a>>b;
            cout<<query(0,0,n-1,a,b)<<endl;
        }
        else{
            cin>>a>>b;//A[a]=b
            update(0,0,n-1,a,b);
        }
    }
    return 0;
}
