#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

struct node* XOR (struct node *a, struct node *b)
{
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void print(Node *root,Node *prev){
    cout<<root->data<<" ";
    if(root->next==prev){
        return;
    }
    print(XOR(root->next,prev),root);
}

int main()
{
    Node *root=NULL;
    int n,a;
    cin>>n;
    root=(Node*)malloc(sizeof(Node));
    cin>>root->data;
    root->next=NULL;
    Node *prev=root;
    Node *pprev=NULL;
    for(int i=1;i<n;i++){
        Node *temp=(Node*)malloc(sizeof(Node));
        cin>>temp->data;
        prev->next=XOR(pprev,temp);
        temp->next=XOR(prev, NULL);
        pprev=prev;
        prev=temp;
    }
    cout<<"left to right=";
    print(root,NULL);
    cout<<endl;
    cout<<"right to left=";
    print(prev,NULL);
    return 0;
}

