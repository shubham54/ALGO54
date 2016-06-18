#include<bits/stdc++.h>

using namespace std;

struct Stack
{
    int data;
    struct Stack *next;
}*top=NULL;

typedef struct Stack st;

void push(int a)
{
    st *p;
    p=(st*)malloc(sizeof(st));
    p->data=a;
    p->next=top;
    top=p;
}

void pop()
{
    st *p;
    p=top;
    if(top==NULL)
        cout<<"stack underflow !!!!!"<<endl;
    else
    {
        top=top->next;
        cout<<"pop element is="<<p->data<<endl;
        free(p);
    }
}

int main()
{
    int choice,a;
    do
    {
        cout<<"enter your choice"<<endl;
        cout<<"1.) push"<<endl;
        cout<<"2.) pop"<<endl;
        cout<<"3.) exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    cout<<"enter the element"<<endl;
                    cin>>a;
                    push(a);
                    break;
                }
            case 2:
                {
                    pop();
                    break;
                }
            case 3:
                {
                    exit(0);
                    break;
                }
            default:
                {
                    cout<<"wrong choice"<<endl;
                }
        }
    }while(choice!=3);
    return 0;
}
