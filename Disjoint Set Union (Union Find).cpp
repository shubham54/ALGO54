#include<bits/stdc++.h>
#define max 1000000

using namespace std;

int A[max],size[max];

void initialize(int n)
{
    for(int i=0;i<n;i++)
    {
        A[i]=i;
        size[i]=1;
    }
}

int root(int i)
{
    while(i!=A[i])
    {
        A[i]=A[A[i]];
        i=A[i];
    }
    return i;
}

bool find(int a,int b)
{
    if(root(a)==root(b))
        return true;
    else
        return false;
}

void join(int a,int b)
{
    int x=root(a);
    int y=root(b);

    if(size[x]>=size[y])
    {
        A[y]=A[x];
        size[x]+=size[y];
    }
    else
    {
        A[x]=A[y];
        size[y]+=size[x];
    }
}

int main()
{
    int n,a,b,q;
    cin>>n>>q;
    initialize(n);
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        join(a,b);
    }
    return 0;
}
