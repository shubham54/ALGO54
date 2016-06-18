#include<bits/stdc++.h>
#define max 10

using namespace std;

int Stack[max];
int i=-1;
void push(int a)
{
    if(i==(max-1))
        cout<<"stack overflow !!!!!!"<<endl;
    else
        Stack[++i]=a;
}

void pop()
{
    if(i==-1)
        cout<<"stack underflow !!!!!"<<endl;
    else
    {
        cout<<"pop element is="<<Stack[i]<<endl;
        i--;
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
                }
            default:
                {
                    cout<<"wrong choice"<<endl;
                }
        }
    }while(choice!=3);
    return 0;
}
