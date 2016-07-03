#include<bits/stdc++.h>

using namespace std;

struct Node
{
    map<char,Node*> a;
    bool flag;

    Node(){flag =false;}
};

void insert(Node *x,string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(x->a.count(s[i])== 0)
        {
            x->a[s[i]] = new Node;
        }
        x=x->a[s[i]];
    }
    x->flag=true;
}

int search(Node *x,string s)
{
    int flag=0;
    for(int i=0;i<s.length();i++)
    {
        if(x->a.count(s[i])== 0){
            flag=1;break;}
        x=x->a[s[i]];
    }
    if(flag==0){
        if(x->flag==true)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

void del(Node *x,string s)
{
   if(search(x,s)){
    for(int i=0;i<s.length();i++)
        x=x->a[s[i]];
   }
   x->flag=false;
}


int main()
{
    struct Node *root= new Node;
    //insert
    insert(root,"abc");
    insert(root,"abcd");
    insert(root,"efgh");
    //search
    cout<<search(root,"abc")<<endl;
    //delete
    del(root,"abc");
    //search
    cout<<search(root,"abc");
    return 0;
}
