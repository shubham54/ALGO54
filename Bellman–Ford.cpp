#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> >V[100001];
int Path[100001];

void bellman_ford(int s,int v)
{
    int a,b,flag=0;
    pair<int,int>PP;
    for(int i=0;i<v;i++){
        Path[i]=INT_MAX;
    }
    Path[s]=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            if(Path[j]!=INT_MAX)
            {
                PP=V[i][j];
                a=PP.first;b=PP.second;
                Path[a]=min(Path[a],Path[i]+b);
            }
        }
    }
    //for negative cycle detection
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            PP=V[i][j];
            a=PP.first;b=PP.second;
            if(Path[j]!=INT_MAX && (Path[i]+b)<Path[a])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1){
        cout<<"Negative cycle exist"<<endl;
    }
    else{
        cout<<"Distance from Source:"<<endl;
        for(int i=0;i<v;i++){
            cout<<Path[i]<<" ";
        }
    }
}

int main()
{
    int v,e,a,b,c;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        V[a].push_back(make_pair(b,c));
    }
    bellman_ford(0,v);
    return 0;
}
