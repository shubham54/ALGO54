#include<bits/stdc++.h>

using namespace std;

int A[100000],seg[150000],lazy[150000];


void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        seg[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {
        seg[node] += (end - start + 1) * val;
        if(start != end)
        {
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);
    updateRange(node*2 + 2, mid + 1, end, l, r, val);
    seg[node] = seg[node*2+1] + seg[node*2+2];
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0)
    {
        seg[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return seg[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2+1, start, mid, l, r);
    int p2 = queryRange(node*2 + 2, mid + 1, end, l, r);
    return (p1 + p2);
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
    int n,q,choice,a,b,val;
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
            cout<<queryRange(0,0,n-1,a,b)<<endl;
        }
        else{
            cin>>a>>b>>val;
            updateRange(0,0,n-1,a,b,val);
        }
    }
    return 0;
}
