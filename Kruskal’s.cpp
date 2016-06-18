#include<bits/stdc++.h>
#define max 100000

using namespace std;

int A[max],size[max];

void intialize(int n)
{
    for(int i=1;i<n;i++)
    {
        A[i]=i;
        size[i]=i;
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
    int v,e,a,b,c,sum=0;
    cin>>v>>e;
    intialize(v);
    pair<int,pair<int,int> >p[e];
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        p[i]=make_pair(c,make_pair(a,b));
    }
    sort(p,p+e,less<pair<int,pair<int,int> > >());
    for(int i=0;i<e;i++)
    {
        c=p[i].first;
        a=p[i].second.first;
        b=p[i].second.second;
        if(!find(a,b))
        {
            join(a,b);
            sum+=c;
        }
    }
    cout<<sum<<endl;
    return 0;
}
