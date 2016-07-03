#include<bits/stdc++.h>

using namespace std;

vector<int>V[1001];
int visit[1001],parent[1001],cost[1000][1000];

bool bfs(int s,int sink)
{
    memset(visit,0,sizeof(visit));
    queue<int>Q;
    Q.push(s);
    visit[s]=1;
    parent[s]=s;
    while(!Q.empty())
    {
        s=Q.front();
        Q.pop();
        for(int i=0;i<V[s].size();i++)
        {
            if(!visit[V[s][i]] && cost[s][V[s][i]])
            {
                parent[V[s][i]]=s;
                visit[V[s][i]]=1;
                Q.push(V[s][i]);
            }
        }
    }
    return (visit[sink]==1)?(true):(false);
}

int ford(int source,int sink)
{
    int maxflow=0;
    while(bfs(source,sink))
    {
        int mi=INT_MAX,j;
        for(int i=sink;i!=source;i=parent[i])
        {
            j=parent[i];
            mi=min(mi,cost[j][i]);
        }
        for(int i=sink;i!=source;i=parent[i])
        {
            j=parent[i];
            cost[j][i]-=mi;
            cost[i][j]+=mi;
        }
        maxflow+=mi;
    }
    return maxflow;
}

int main()
{
    int v,e,a,b,c;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;//vertex(a,b) cost c
        V[a].push_back(b);
        V[b].push_back(a);
        cost[a][b]=c;
        cost[b][c]=0;
    }
    int ans=ford(0,v-1);//Assume source is 0 sink is v-1
    cout<<"The maximum possible flow is= "<<ans<<endl;
    return 0;
}
