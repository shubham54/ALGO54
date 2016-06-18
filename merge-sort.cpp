#include<bits/stdc++.h>

using namespace std;

void merge(int a[],int start,int mid,int end)
{
    int arr[end-start+1];
    int k=0,p=start,q=mid+1;
    for(int i=start;i<=end;i++)
    {
        if(p>mid)
            arr[k++]=a[q++];
        else if(q>end)
            arr[k++]=a[p++];
        else if(a[p]<a[q])
            arr[k++]=a[p++];
        else
            arr[k++]=a[q++];
    }
    for(int i=0;i<k;i++)
    {
        a[start++]=arr[i];
    }
}

void divide(int a[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        divide(a,start,mid);
        divide(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    divide(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

