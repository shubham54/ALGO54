#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j;
    string s;
    getline(cin,s);//input the string with spaces too
    int l=s.length();
    int dp[l][l];
    for(i=0;i<l;i++)
    {
        for(j=0;j<l;j++)
        {
            if(i==j)
                dp[i][j]=1;
            else
                dp[i][j]=0;
        }
    }
    i=0;
    for(int k=0;k<l;k++)
    {
        j=k+1;
        while(j<l)
        {
            if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            i++;j++;
        }
        i=0;
    }
    cout<<"Answer id="<<dp[0][l-1]<<endl;
    //matrix
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
