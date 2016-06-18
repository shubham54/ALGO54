#include<bits/stdc++.h>

using namespace std;

void binary(int a[],int s,int n)
{
    int start=0,end=n-1,mid,flag=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(a[mid]==s)
        {
            flag=1;
            break;
        }
        else if(a[mid]>s)
            end=mid-1;
        else
            start=mid+1;
    }
    if(flag==1)
        cout<<"FOUND"<<endl;
    else
        cout<<"NOT FOUND"<<endl;
}

int main()
{
    int n,s;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>s;
    binary(a,s,n);
    return 0;
}
