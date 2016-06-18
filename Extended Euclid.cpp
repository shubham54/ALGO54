//Ax+By=GCD(A,B)
#include<bits/stdc++.h>

using namespace std;

int x,y,gcd;

void extended(int a,int b)
{
    if(b==0)
    {
        gcd=a;
        x=1;
        y=0;
    }
    else
    {
        extended(b,a%b);
        int temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    extended(a,b);
    cout<<"gcd="<<gcd<<endl;
    cout <<"Coefficient x and y are: "<<x <<" and  "<<y<<endl;
    return 0;
}
