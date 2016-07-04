#include<bits/stdc++.h>

using namespace std;

int path[1000][1000];
int job[1001],visit[1000];

bool check(int a,int v)
{
    for(int i=0;i<v;i++)
    {
        if(path[a][i] && !visit[i])
        {
            visit[i]=1;

            if(job[i]<0 || check(job[i],v))
            {
                job[i]=a;
                return true;
            }
        }
    }
    return false;
}

void match(int v)
{
    int ans=0;

    memset(job,-1,sizeof(job));

    for(int i=0;i<v;i++)
    {
        memset(visit,0,sizeof(visit));
        if(check(i,v))
            ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;//v is vertex e is edge
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;//a-b edge
        path[a][b]=1;
    }
    match(v);
    return 0;
}
