#include<bits/stdc++.h>

using namespace std;

void LPS(string pat,int *lps)
{
    int i=0,j=1;
    lps[0]=0;
    while(j<pat.length())
    {
        if(pat[i]==pat[j])
        {
            i++;
            lps[j]=i;
            j++;
        }
        else
        {
            if(i!=0)
                i=lps[i-1];
            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
}

void kmp(string txt,string pat)
{
    int m=pat.length();
    int n=txt.length();

    int lps[m+1];
    LPS(pat,lps);

    int i=0,j=0;
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            printf("pattern found at=%d\n",i-m);
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}

int main()
{
    string text,pat;
    cin>>text>>pat;
    kmp(text,pat);
    return 0;
}
