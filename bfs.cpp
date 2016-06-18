#include<bits/stdc++.h>
#define max 1000
using namespace std;

int visit[max];
vector<int>myvec[max];

void dfs(int a)
{
    queue<int>myqueue;
    myqueue.push(a);
    while(!myqueue.empty())
    {
        a=myqueue.front();
        cout<<a<<" ";
        visit[a]=true;
        myqueue.pop();
        for(int i=0;i<myvec[a].size();i++)
        {
            if(!visit[myvec[a][i]])
            {
                myqueue.push(myvec[a][i]);
                visit[myvec[a][i]]=true;
            }
        }
    }
}

int main()
{
    int a,b,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        myvec[a].push_back(b);
        myvec[b].push_back(a);
    }
    int source;
    cin>>source;
    dfs(source);
    return 0;
}

