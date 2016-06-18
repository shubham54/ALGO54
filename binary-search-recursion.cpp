#include<bits/stdc++.h>

using namespace std;

bool binary(int a[],int s,int start,int end)
{
   if(start<=end)
   {
       int mid=(start+end)/2;
       if(a[mid]==s)
        return true;
       else if(a[mid]>s)
        binary(a,s,start,mid-1);
       else
        binary(a,s,mid+1,end);
   }
   else
        return false;
}

int main()
{
    int n,s;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>s;
    if(binary(a,s,0,n-1))
        cout<<"FOUND"<<endl;
    else
        cout<<"NOT FOUND"<<endl;
    return 0;
}
