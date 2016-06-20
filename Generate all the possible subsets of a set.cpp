#include<bits/stdc++.h>

using namespace std;

void generates(int A[],int n)
{
    for(int i=0;i<pow(2,n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                cout<<A[j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    generates(A,n);
    return 0;
}


