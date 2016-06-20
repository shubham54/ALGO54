#include<bits/stdc++.h>

using namespace std;

int counts(int n)
{
    int con=0;
    while(n!=0)
    {
        n=n&(n-1);
        con++;
    }
    return con;
}

int main()
{
    int n,test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cout<<counts(n)<<endl;
    }
    return 0;
}
