#include<bits/stdc++.h>
#define max 1000000

using namespace std;

typedef pair<int,int> pp;
vector<pp>myvec[max];
int visit[max];

int prims(int a)
{
    int b,c,sum=0;
    pp P;
    priority_queue<pp,vector<pp>,greater<pp> >Q;
    Q.push(make_pair(0,a));
    while(!Q.empty())
    {
        P=Q.top();
        Q.pop();
        a=P.second;
        c=P.first;
        if(visit[a]==1)
            continue;
        sum+=c;
        visit[a]=1;
        for(int i=0;i<myvec[a].size();i++)
        {
            P=myvec[a][i];
            b=P.first;
            c=P.second;
            if(!visit[b])
                Q.push(make_pair(c,b));
        }
    }
    return sum;
}

int main()
{
    int v,e,a,b,c;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        myvec[a].push_back(make_pair(b,c));
        myvec[b].push_back(make_pair(a,c));
    }
    cout<<prims(1)<<endl;
    return 0;
}
