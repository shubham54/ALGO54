#include<bits/stdc++.h>
#define max 1000
using namespace std;

int visit[max];
vector<int>myvec[max];

void dfs(int a)
{
    stack<int>mystack;
    mystack.push(a);
    while(!mystack.empty())
    {
        a=mystack.top();
        cout<<a<<" ";
        visit[a]=true;
        mystack.pop();
        for(int i=0;i<myvec[a].size();i++)
        {
            if(!visit[myvec[a][i]])
            {
                mystack.push(myvec[a][i]);
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
