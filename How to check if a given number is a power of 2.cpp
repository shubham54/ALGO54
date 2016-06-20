#include<bits/stdc++.h>

using namespace std;

void check(int n)
{
    if(n==0 || (n&(n-1)))
        cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
}

int main()
{
    int n,test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        check(n);
    }
    return 0;
}

