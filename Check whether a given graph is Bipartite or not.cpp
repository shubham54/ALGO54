#include<bits/stdc++.h>

using namespace std;

vector<int>myvec[100001];
int visit[100001];
int flip(int a)
{
    return (a==1)?-1:1;
}

bool BP(int a)
{
    int isBipartite=1;//2 color that is 1 and -1
    queue<int>Q;
    Q.push(a);
    visit[a]=-1;
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        for(int i=0;i<myvec[a].size();i++)
        {
            int b=myvec[a][i];
            if(visit[b]==0 && visit[b]!=visit[a])
            {
                visit[b]=flip(visit[a]);
                Q.push(b);
            }
            else if(visit[b]==visit[a])
            {
                isBipartite=0;
                break;
            }
        }
        if(!isBipartite){
            break;
        }
    }
    return (isBipartite)?true:false;
}

void checkB(int v)
{
    int flag=1;
    for(int i=1;i<=v;i++){
        if(!visit[i]){
            if(BP(i)==false){
                flag=0;
                break;
            }

        }
    }
    (flag)?cout<<"YES\n":cout<<"NO\n";
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        myvec[a].push_back(b);
        myvec[b].push_back(a);
    }
    checkB(v);
    return 0;
}
