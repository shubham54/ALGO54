#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        int mi=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mi])
                mi=j;
        }
        swap(a[mi],a[i]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

