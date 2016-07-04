#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int A[1000][1000],P[1000][1000];
ll dp[1000][1000];

void intialize()
{
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(i==j){
                A[i][j]=0;
            }
            else{
                A[i][j]=INT_MAX;
            }
            P[i][j]=-1;
        }
    }
}

void flyod(int v)
{
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dp[i][j]=A[i][j];
            if(A[i][j]!=INT_MAX && i!=j)
                P[i][j]=j;
        }
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dp[i][k]+dp[k][j]<dp[i][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    P[i][j]=P[i][k];
                }
            }
        }
    }

    cout<<"Matrix is:"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dp[i][j]==INT_MAX){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    cout<<"Path Matrix is:"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
}

void path(int u,int v)//To display path
{
    if(P[u][v]==-1){
        cout<<"Path Not Found"<<endl;
    }
    else{
        int i;
        vector<int>L;
        L.push_back(u);
        while(u!=v){
            u=P[u][v];
            L.push_back(u);
        }
        for(i=0;i<L.size()-1;i++){
            cout<<L[i]<<"->";
        }
        cout<<L[i]<<endl;
    }
}

int main()
{
    int v,e,a,b,c,q;
    cin>>v>>e;//v is vertex e edge;
    intialize();
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;// a-b edge c cost
        A[a][b]=c;
    }
    flyod(v);
    cin>>q;//query to find path of
    while(q--){
        cin>>a>>b;
        path(a,b);
    }
    return 0;
}
