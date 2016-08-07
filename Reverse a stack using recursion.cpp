/*shubham54*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
#include <cmath>
#define ll long long int

using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

void push(Node **temp,int a)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=a;
    ptr->next=*temp;
    *temp=ptr;
}

void print(Node *ptr)
{
    if(ptr==NULL)
        return;
    cout<<ptr->data<<" ";
    print(ptr->next);
}

void pop(Node **ptr)
{
    Node *temp=*ptr;
    *ptr=(*ptr)->next;
    free(temp);
}

void rev(Node **ptr,int a)
{
    if(*ptr==NULL)
        push(ptr,a);
    else
    {
            int b=(*ptr)->data;
            pop(ptr);
            rev(ptr,a);
            push(ptr,b);
    }
}

void reversee(Node **ptr)
{
    if(*ptr!=NULL)
    {
        int a=(*ptr)->data;
        pop(ptr);
        reversee(ptr);
        rev(ptr,a);
    }
}

int main()
{
    int n;
    cin>>n;int a;
    Node *root=NULL;
    for(int i=0;i<n;i++){
        cin>>a;
        push(&root,a);
    }
    cout<<"Original Stack:\n";
    print(root);
    reversee(&root);
    cout<<endl<<"New Stack:"<<endl;
    print(root);
    return 0;
}
