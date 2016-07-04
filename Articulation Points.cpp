#include<bits/stdc++.h>

using namespace std;

vector<int>myvec[100001];
int parent[100001],visit[100001],ap[100001],low[100001],high[100001];

void dfs(int a)
{
    static int time=0;
    int child=0;
    visit[a]=1;
    low[a]=high[a]=++time;
    for(int i=0;i<myvec[a].size();i++) {
        int b=myvec[a][i];
        if(!visit[b]) {

            child++;
            parent[b]=a;

            dfs(b);//recursion

            low[a]=min(low[a],low[b]);//updating low value

            if(parent[a]==-1 && child>1) {//root should have at least 2 independent child
                ap[a]=1;
            }

            if(parent[a]!=-1 && high[a]<=low[b]){
                ap[a]=1;
            }

        }
        else if(b!=parent[a]){
            low[a]=min(low[a],high[b]);
        }
    }
}


void articulation(int v)
{
    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        visit[i]=0;
        ap[i]=0;
    }
    for(int i=0;i<v;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    cout<<"Articulation points are= ";
    for(int i=0;i<v;i++)
    {
        if(ap[i])
            cout<<i<<" ";
    }
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;//v is vertex e edges
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        myvec[a].push_back(b);
        myvec[b].push_back(a);
    }
    articulation(v);
    return 0;
}
