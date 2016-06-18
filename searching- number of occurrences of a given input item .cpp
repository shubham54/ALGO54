//Given a sorted array A with possible duplicate elements and you need to find the number of occurrences of a given input item (assuming the element is present in the array).

#include<bits/stdc++.h>

using namespace std;

int firstoccurance(int a[],int s,int start,int end)
{
    while(end-start>1)
    {
        int mid=start+(end-start)/2;
        if(a[mid]>=s)
            end=mid;
        else
            start=mid;
    }
    return end;
}

int lastoccurnance(int a[],int s,int start,int end)
{
    while(end-start>1)
    {
        int mid=start+(end-start)/2;
        if(a[mid]<=s)
            start=mid;
        else
            end=mid;
    }
    return start;
}

int main()
{
    int n,s;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>s;
    int left=firstoccurance(a,s,-1,n-1);
    int right=lastoccurnance(a,s,0,n);
    cout<<left<<" "<<right<<endl;
    if(a[left]==s && a[right]==s)
        cout<<right-left+1<<endl;
    else
        cout<<0<<endl;
    return 0;
}
