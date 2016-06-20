#include<bits/stdc++.h>

using namespace std;

int Histogram(int A[],int n)
{
    int i,top,sum,ans=INT_MIN;
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
    return ans;
}

int main()
{
    int n,m,ans=INT_MIN;
    cin>>n>>m;
    int B[n][m],A[m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>B[i][j];
        }
    }
    for(int i=0;i<m;i++)
        A[i]=B[0][i];
    ans=Histogram(A,m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(B[i][j]==0)
                A[j]=0;
            else
                A[j]+=B[i][j];
        }
        ans=max(ans,Histogram(A,m));
    }
    cout<<"Answer is="<<ans<<endl;
    return 0;
}

