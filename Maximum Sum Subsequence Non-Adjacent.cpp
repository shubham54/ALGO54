#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,in,ex,temp;//in is inclusive and ex exclusive
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    in=A[0];ex=0;
    for(int i=1;i<n;i++){
        temp=in;
        in=max(in,ex+A[i]);
        ex=temp;
    }
    cout<<"Answer is= "<<in<<endl;
    return 0;
}
