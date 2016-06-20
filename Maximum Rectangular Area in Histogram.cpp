#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,n,top,sum,ans=INT_MIN;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    stack<int>mystack;
    for(i=0;i<n;)
    {
        if(mystack.empty())
            mystack.push(i),i++;
        else
        {
            if(A[mystack.top()]<=A[i])
                mystack.push(i),i++;
            else
            {
                while(!mystack.empty() && A[mystack.top()]>A[i])
                {
                    top=mystack.top();
                    mystack.pop();
                    if(mystack.empty())
                        sum=A[top]*i;
                    else
                        sum=A[top]*(i-mystack.top()-1);
                    ans=max(ans,sum);
                }
            }
        }
    }
    while(!mystack.empty())
    {
        top=mystack.top();
        mystack.pop();
        if(mystack.empty())
            sum=A[top]*i;
        else
            sum=A[top]*(i-mystack.top()-1);
        ans=max(ans,sum);
    }
    cout<<"Answer is="<<ans<<endl;
    return 0;
}

