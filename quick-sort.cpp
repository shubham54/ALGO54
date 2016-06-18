#include<bits/stdc++.h>

using namespace std;

int part(int a[],int start,int end)
{
    int piv=a[start];
    int i=start+1;
    for(int j=start+1;j<=end;j++)
    {
        if(a[j]<piv)
        {
            swap(a[j],a[i]);
            i+=1;
        }
    }
    swap(a[start],a[i-1]);
    return i-1;
}

void quick_sort(int a[],int start,int end)
{
    if(start<end)
    {
        int mid=part(a,start,end);
        quick_sort(a,start,mid-1);
        quick_sort(a,mid+1,end);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

