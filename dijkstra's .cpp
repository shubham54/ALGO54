#include<bits/stdc++.h>
#define max 1000
using namespace std;

int visit[max],dist[max],parent[max];//parent array to trace the path
vector<pair<int,int> >myvec[max];

void dfs(int a)
{
    queue<pair<int,int> >myqueue;
    pair<int,int> p;
    myqueue.push(make_pair(a,0));
    dist[a]=0;
    while(!myqueue.empty())
    {
        p=myqueue.front();
        a=p.first;
        visit[a]=true;
        myqueue.pop();
        for(int i=0;i<myvec[a].size();i++)
        {
            p=myvec[a][i];
            if(!visit[p.first])
            {

                myqueue.push(p);
                visit[p.first]=true;
            }
            if(dist[p.first]>p.second+dist[a])
               dist[p.first]=p.second+dist[a],parent[p.first]=a;
        }
    }
}

void printpath(int source,int a)
{
    if(a!=source)
    {
        printpath(source,parent[a]);
        cout<<a<<" ";
    }
    else
    {
        cout<<source<<" ";
        return;
    }

}
int main()
{
    int a,b,n,cost,e;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>cost;
        myvec[a].push_back(make_pair(b,cost));
        myvec[b].push_back(make_pair(a,cost));
    }
    for(int i=0;i<=n;i++)
        dist[i]=INT_MAX;
    int source;
    cin>>source;
    dfs(source);
    cin>>e;//enter the node whose path you want to see from source node
    printpath(source,e);
    cout<<endl;
    for(int i=0;i<=n;i++)
        cout<<i<<"="<<dist[i]<<endl;
    return 0;
}


