#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll expo(ll a,ll b,ll mod)
{
    ll r=1;
    while(b>0)
    {
        if(b%2==1)
            r=((r%mod)*(a%mod))%mod;
        a=((a%mod)*(a%mod))%mod;
        b/=2;
    }
    return r;
}

int main()
{
    ll base,exp,mod;
    cin>>base>>exp>>mod;
    cout<<"Answer="<<expo(base,exp,mod)<<endl;
    return 0;
}
