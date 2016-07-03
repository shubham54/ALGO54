#include<bits/stdc++.h>

using namespace std;

void Zfunc(string s,int Z[],int n)
{
    int left=0,right=0,k;
    Z[0]=0;
    for(int i=1;i<n;i++){
        if(i>right){
            left=right=i;
            while(right<n && s[right]==s[right-left]){
                right++;
            }
            Z[i]=right-left;
            right--;
        }
        else{
            k=i-left;
            if(Z[k]<right-i+1){
                Z[i]=Z[k];
            }
            else{
                left=i;
                while(right<n && s[right]==s[right-left]){
                    right++;
                }
                Z[i]=right-left;
                right--;
            }
        }
    }
}


int main()
{
    string pat,txt,s;
    cin>>pat>>txt;
    s=pat+'$'+txt;
    int n=s.length();
    int Z[n+1];
    Zfunc(s,Z,n);
    for(int i=1;i<n;i++){
        if(Z[i]==pat.length()){
            cout<<"Pattern found at index="<<abs(i-pat.length())<<endl;
        }
    }
    return 0;
}
