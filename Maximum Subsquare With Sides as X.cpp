#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,ans=0,temp;
    cin>>n>>m;
    char A[n][m];
    pair<int,int>P[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    if(A[0][0]=='X'){
        P[0][0]=make_pair(1,1);
    }
    else{
        P[0][0]=make_pair(0,0);
    }
    for(int i=1;i<n;i++){
        if(A[i][0]=='X'){
            P[i][0]=make_pair(1+P[i-1][0].first,1);
        }
        else{
            P[i][0]=make_pair(0,0);
        }
    }
    for(int i=1;i<=m;i++){
        if(A[0][i]=='X'){
            P[0][i]=make_pair(1,1+P[0][i-1].second);
        }
        else{
            P[0][i]=make_pair(0,0);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i][j]=='X'){
                P[i][j]=make_pair(1+P[i-1][j].first,1+P[i][j-1].second);

            }
            else{
                P[i][j]=make_pair(0,0);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            temp=min(P[i][j].first,P[i][j].second);
            while(temp!=0 && temp>ans){
                if(P[i][j-temp+1].first>=temp && P[i-temp+1][j].second>=temp){
                    ans=max(ans,temp);
                    break;
                }
                else{
                    temp--;
                }
            }
        }
    }
    cout<<"Answer is= "<<ans<<endl;
    return 0;
}
