#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,k;
    cin>>n;
    int A[n];pair<int,int>P[n][n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        P[i][i]=make_pair(A[i],0);
    }
    for(int i=1;i<n;i++){
        k=0;
        for(int j=i;j<n;j++){
            a=A[k]+P[k+1][j].second;
            b=A[j]+P[k][j-1].second;
            if(a>b){
                P[k][j]=make_pair(a,P[k+1][j].first);
            }
            else{
                P[k][j]=make_pair(b,P[k][j-1].first);
            }
            k++;
        }
    }
    cout<<"First Player="<<P[0][n-1].first<<endl;
    cout<<"Second Player="<<P[0][n-1].second<<endl;
    //matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"("<<P[i][j].first<<","<<P[i][j].second<<") ";
        }
        cout<<endl;
    }
    return 0;
}
